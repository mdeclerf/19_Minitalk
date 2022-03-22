/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:41:00 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/13 10:52:56 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** This file contains : 
void	ft_putchar(char c)
void	ft_putstr(char *str)
void	ft_putnbr(int n)
char	*addchar(char *s1, char s2)
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

char	*addchar_bis(char *cat, char s2)
{
	cat = malloc(sizeof(char) * 2);
	if (cat == NULL)
		return (NULL);
	cat[0] = s2;
	cat[1] = '\0';
	return (cat);
}

char	*addchar(char *s1, char s2)
{
	size_t	i;
	size_t	j;
	char	*cat;

	cat = NULL;
	if (! s1)
	{
		cat = addchar_bis(cat, s2);
		return (cat);
	}
	if (! s2)
		return ((char *)s1);
	i = 0;
	j = 0;
	cat = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (cat == NULL)
		return (NULL);
	while (s1[j] != '\0')
		cat[i++] = s1[j++];
	free(s1);
	cat[i] = s2;
	cat[i + 1] = '\0';
	return (cat);
}
