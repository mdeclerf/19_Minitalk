/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:40:42 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/13 11:15:50 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_backslashzero(pid_t server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(server_pid, SIGUSR2);
		usleep(90);
		i++;
	}
}

void	send_binary(pid_t server_pid, char *message)
{
	int	j;
	int	i;
	int	marker;

	i = 0;
	while (message[i])
	{
		j = 0;
		marker = 128;
		while (j < 8)
		{
			if ((marker & message[i]) == marker)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(90);
			marker = marker >> 1;
			j++;
		}
		i++;
	}
	send_backslashzero(server_pid);
}

void	sig_handler(int signum)
{
	(void)signum;
	ft_putstr("Message received by server\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		ft_putstr("Invalid number of arguments\n");
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr("Invalid pid\n");
		return (0);
	}
	message = NULL;
	message = message_compo_bonus(argv, message);
	send_binary(server_pid, message);
	while (1)
		signal(SIGUSR2, sig_handler);
	return (0);
}
