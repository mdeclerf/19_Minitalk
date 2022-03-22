/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:40:54 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/08/13 10:53:31 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
** This file contains : 
int	ft_atoi(const char *str)
int	ft_strlen(const char *s)
char	*ft_strjoin(char *s1, char *s2)
*/

static	int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	return_value;

	i = 0;
	sign = 1;
	return_value = 0;
	while (*str != '\0' && ft_isspace(*str) == 0)
		str++;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if ((i >= 18 || return_value > 1ull << 63) && sign == 1)
			return (-1);
		if ((i >= 18 || return_value > 1ull << 63) && sign == -1)
			return (0);
		return_value = (return_value * 10) + (str[i] - '0');
		i++;
	}
	return (return_value * sign);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	int		j;
	char	*cat;

	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	cat = (char *)malloc(sizeof(char) * (len + 1));
	if (cat == NULL)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
		cat[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		cat[i++] = s2[j++];
	free(s1);
	cat[i] = '\0';
	return (cat);
}
