/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:43 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/10 12:51:19 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_struct	sig_handler_arobase_eof(t_struct stru)
{
	if (stru.cha == '@' && stru.arobase == 0)
	{
		stru.len = ft_atoi(stru.str);
		free(stru.str);
		stru.str = malloc(sizeof(char) * stru.len + 1);
		if (!stru.str)
			return (stru);
		stru.arobase = 1;
		stru = struct_init(stru);
	}
	else if (stru.cha == 0 && stru.arobase == 1)
	{
		stru.str[stru.count] = '\0';
		ft_putstr(stru.str);
		ft_putchar('\n');
		free(stru.str);
		stru.str = NULL;
		stru.arobase = 0;
		stru.count = 0;
		stru = struct_init(stru);
	}
	return (stru);
}

t_struct	sig_handler_len(t_struct stru)
{
	stru.str = addchar(stru.str, stru.cha);
	if (! stru.str)
	{
		free(stru.str);
		exit(EXIT_FAILURE);
	}
	stru = struct_init(stru);
	return (stru);
}
