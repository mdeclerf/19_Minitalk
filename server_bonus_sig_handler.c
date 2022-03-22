/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus_sig_handler.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:28:00 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/13 11:10:08 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bonus	sighandler_len(t_bonus stru)
{
	stru.str = addchar(stru.str, '\0');
	if (! stru.str)
	{
		free(stru.str);
		exit(EXIT_FAILURE);
	}
	stru.len = ft_atoi(stru.str);
	stru.str = ft_bzero(stru.str, ft_strlen(stru.str));
	stru = struct_init_bonus(stru);
	stru.arobase = 1;
	return (stru);
}

t_bonus	sighandler_client_pid(t_bonus stru)
{
	stru.str = addchar(stru.str, '\0');
	if (! stru.str)
	{
		free(stru.str);
		exit(EXIT_FAILURE);
	}
	stru.client_pid = ft_atoi(stru.str);
	free(stru.str);
	stru.str = malloc(sizeof(char) * (stru.len + 1));
	if (! stru.str)
		return (stru);
	stru.str = ft_bzero(stru.str, stru.len + 1);
	stru = struct_init_bonus(stru);
	stru.hashtag = 1;
	stru.count = 0;
	return (stru);
}

t_bonus	sighandler_eof(t_bonus stru)
{
	stru.str[stru.count] = '\0';
	ft_putstr(stru.str);
	ft_putchar('\n');
	stru.arobase = 0;
	stru.hashtag = 0;
	stru.count = 0;
	stru.len = 0;
	stru = struct_init_bonus(stru);
	usleep(300);
	kill(stru.client_pid, SIGUSR2);
	ft_putstr("Confirmation of reception sent to client\n");
	free(stru.str);
	stru.str = NULL;
	stru.client_pid = 0;
	return (stru);
}

t_bonus	sighandler_addchar(t_bonus stru)
{
	stru.str = addchar(stru.str, stru.cha);
	if (! stru.str)
	{
		free(stru.str);
		exit(EXIT_FAILURE);
	}
	stru = struct_init_bonus(stru);
	return (stru);
}

t_bonus	sighandler_message(t_bonus stru)
{
	stru.str[stru.count++] = stru.cha;
	stru = struct_init_bonus(stru);
	return (stru);
}
