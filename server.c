/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:40:47 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/10 13:30:43 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_server_pid(pid_t pid_server)
{
	ft_putstr("PID SERVER : ");
	ft_putnbr(pid_server);
	ft_putchar('\n');
}

/*
** This function initializes a part of the static struct and will be called
after the complete reception of each char.
*/
t_struct	struct_init(t_struct stru)
{
	stru.count_bits = 0;
	stru.cha = 0;
	return (stru);
}

/*
** This function is the handler function used by signal in the main. It is the
same in case of the reception of a SIGUSR1 and SIGUSR2 signal.  If the signal 
is SIGUSR1, we need to place a 1 at the corresponding spot in the 8 bits of 
each char. We modifiy the variable stru.cha set to 0 using 128 
(in binary 10000000) and a shift right operator. We shift the digit 1 in 128 
of count notches(crans) to the right and add that to the total of the char. 
If the signal is SIGUSR2 (stands for a '0')
we only increment the counter. Once we read a full char we have different 
possibilities : the char is the delimiter, which mean we have the length of
the message, we can malloc stru.str. The char is not the delimiter and it is 
still set to 0 : we append each char to the previous to get the full length. 
The char is a \0, we print the message and reinitialize all the struct. 
Else (the char is part of the message) we just add it to the malloced 
string with the help of a counter.
*/

void	sig_handler(int signum)
{
	static t_struct	stru;

	if (signum == SIGUSR1)
	{
		stru.cha += 128 >> stru.count_bits;
		stru.count_bits ++;
	}
	else if (signum == SIGUSR2)
		stru.count_bits ++;
	if (stru.count_bits == 8)
	{
		if ((stru.cha == '@' && stru.arobase == 0)
			|| (stru.cha == 0 && stru.arobase == 1))
			stru = sig_handler_arobase_eof(stru);
		else if (stru.cha != 0 && stru.arobase == 0)
			stru = sig_handler_len(stru);
		else
		{
			stru.str[stru.count++] = stru.cha;
			stru = struct_init(stru);
		}
	}
}

/*
** The first thing the server is supposed to do is to display its
PID, that will be used as a param by ./client. The get_pid function
stores it in a variable used by print_server_pid.
The signal functions (takes as params a signal number and a handler
function that describes what to be done if this signal is received).
After the execution of the handler function, the process starts again
where it was interrupted.
The pause function suspends the program execution until a new signal
arrives.
*/
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
