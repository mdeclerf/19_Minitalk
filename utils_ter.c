/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 10:18:26 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/13 10:54:02 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** This file contains : 
char	*ft_itoa(int n)
char	*ft_bzero(char *s, int n)
*/

static	int	malloc_size(int n)
{
	int	i;

	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		i = 1;
	}
	else
		i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	void	filling(int n, int size, int decalage, char *string)
{
	while (size > decalage)
	{
		string[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	char	*string;
	int		decalage;
	int		size;

	string = malloc(sizeof(char) * malloc_size(n) + 1);
	if (!string)
		return (NULL);
	decalage = 0;
	size = malloc_size(n);
	if (n < 0)
	{
		decalage = 1;
		string[0] = '-';
		n = n * (-1);
	}
	if (n == -2147483648)
	{
		decalage = 2;
		string[0] = '-';
		string[1] = '2';
		n = 147483648;
	}
	filling(n, size, decalage, string);
	string[size] = '\0';
	return (string);
}

char	*ft_bzero(char *s, int n)
{
	int			i;

	i = 0;
	if (! s)
		return (NULL);
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}
