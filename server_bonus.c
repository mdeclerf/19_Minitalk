/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:40:47 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/13 11:14:42 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bonus	struct_init_bonus(t_bonus stru)
{
	stru.count_bits = 0;
	stru.cha = 0;
	return (stru);
}

void	print_server_pid(pid_t pid_server)
{
	ft_putstr("PID SERVER_BONUS : ");
	ft_putnbr(pid_server);
	ft_putchar('\n');
}

/*
** Composition of the message :
len of the message @ client pid # message 
*/

void	sig_handler(int signum)
{
	static t_bonus	stru;

	if (signum == SIGUSR1)
	{
		stru.cha += 128 >> stru.count_bits;
		stru.count_bits ++;
	}
	else if (signum == SIGUSR2)
		stru.count_bits ++;
	if (stru.count_bits == 8)
	{
		if (stru.cha == '@' && stru.arobase == 0 && stru.hashtag == 0)
			stru = sighandler_len(stru);
		else if (stru.cha == '#' && stru.hashtag == 0 && stru.arobase == 1)
			stru = sighandler_client_pid(stru);
		else if (stru.cha != 0 && (stru.arobase == 0 || stru.hashtag == 0))
			stru = sighandler_addchar(stru);
		else if (stru.cha != 0 && stru.arobase == 1 && stru.hashtag == 1)
			stru = sighandler_message(stru);
		else
			stru = sighandler_eof(stru);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;

	(void)argc;
	(void)argv;
	pid_server = getpid();
	print_server_pid(pid_server);
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}
