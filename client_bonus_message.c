/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus_message.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:53:39 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/13 11:01:19 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*message_pid(char *client_pid)
{
	client_pid = ft_itoa(getpid());
	if (! client_pid)
	{
		free(client_pid);
		exit(EXIT_FAILURE);
	}
	client_pid = addchar(client_pid, '#');
	if (! client_pid)
	{
		free(client_pid);
		exit(EXIT_FAILURE);
	}
	return (client_pid);
}

char	*len(char **argv, char *message)
{
	char	*message_len;

	message_len = ft_itoa(ft_strlen(argv[2]));
	if (! message_len)
	{
		free(message);
		free(message_len);
		exit(EXIT_FAILURE);
	}
	message_len = addchar(message_len, '@');
	if (! message_len)
	{
		free(message);
		free(message_len);
		exit(EXIT_FAILURE);
	}
	return (message_len);
}

/*
** Composition of the message :
len of the message @ client pid # message 
*/
char	*message_compo_bonus(char **argv, char *message)
{
	char	*message_len;
	char	*client_pid;

	message = argv[2];
	client_pid = NULL;
	client_pid = message_pid(client_pid);
	message = ft_strjoin(client_pid, message);
	if (! message)
	{
		free(message);
		exit(EXIT_FAILURE);
	}
	message_len = len(argv, message);
	message = ft_strjoin(message_len, message);
	if (! message)
	{
		free(message);
		free(message_len);
		exit(EXIT_FAILURE);
	}
	return (message);
}
