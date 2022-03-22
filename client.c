/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:40:42 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/13 10:50:30 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** This function sends 8 x 0 to ./server (we will need to have a '\0' at the
reception to print all the message once the totality has been received and not
char by char).
*/
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

/*
** This function converts the string message to binary (8 bits in a char)
and send a SIGUSR1 to ./server in case of a '1' and SIGUSR2 in case of a '0'.
The int marker = 128 because in binary 128->10000000. We iterate through
message and for each char set a variable j. In a while loop going to 8, we
use the & bitshifting operator to compare the marker to the char
(&  : compares the bits of marker to the bits of message[i] and generates
a result of 1 if both bits are 1, otherwise return 0). If the result of
the operation is the marker we send a '1' to server, otherwise a '0'
(with kill : The command kill sends the specified signal
to the specified processes or process groups.) We then shift the 1 digit in
10000000 to the right (01000000 etc..) and suspend the execution to give
enough time to server between each signal. To finish the string we need
to send a '\0'.
*/
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

/*
** The server_pid is passed to the ./client as a first argument. It is converted 
to an int and the length of the message is appended before the message, with
a specific delimiter at then end. It will be used to make a malloc of the
right size for the server to print the message in one go : 
len_message@message
*/
char	*message_compo(char **argv, char *message, char *message_len)
{
	message = argv[2];
	message_len = ft_itoa(ft_strlen(message));
	if (! message_len)
	{
		free(message_len);
		exit(EXIT_FAILURE);
	}
	message_len = addchar(message_len, '@');
	if (! message_len)
	{
		free(message_len);
		exit(EXIT_FAILURE);
	}
	message = ft_strjoin(message_len, message);
	if (! message)
	{
		free(message);
		exit(EXIT_FAILURE);
	}
	return (message);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	char	*message_len;

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
	message_len = NULL;
	message = message_compo(argv, message, message_len);
	send_binary(server_pid, message);
	return (0);
}
