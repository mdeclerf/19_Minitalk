/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 11:42:43 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/10 15:48:04 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_struct
{
	int		count_bits;
	char	*str;
	char	cha;
	int		arobase;
	int		len;
	int		count;
}	t_struct;

/*
** Bonus
*/
typedef struct s_bonus
{
	int		count_bits;
	char	*str;
	char	cha;
	int		arobase;
	int		len;
	int		count;
	int		client_pid;
	int		hashtag;
}	t_bonus;

/*
** Utils
*/
int			ft_atoi(const char *str);
int			ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int n);
char		*ft_bzero(char *s, int n);
void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int n);
char		*addchar(char *s1, char s2);

/*
** Mandatory part
*/
t_struct	struct_init(t_struct stru);
t_struct	sig_handler_arobase_eof(t_struct stru);
t_struct	sig_handler_len(t_struct stru);

/*
** Bonus
*/
t_bonus		struct_init_bonus(t_bonus stru);
t_bonus		sighandler_len(t_bonus stru);
t_bonus		sighandler_client_pid(t_bonus stru);
t_bonus		sighandler_eof(t_bonus stru);
t_bonus		sighandler_addchar(t_bonus stru);
t_bonus		sighandler_message(t_bonus stru);
char		*message_compo_bonus(char **argv, char *message);

#endif
