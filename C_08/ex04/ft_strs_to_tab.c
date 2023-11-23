/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:48:15 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/16 12:50:11 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		l;
	char	*dup_str;

	l = 0;
	if (src == NULL)
		return (0);
	while (src[l] != '\0')
		l++;
	dup_str = (char *)malloc(sizeof(char) * (l + 1));
	if (dup_str == NULL)
		return (0);
	i = 0;
	while (i <= l)
	{
		dup_str[i] = src[i];
		i++;
	}
	return (dup_str);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stocks;
	int			i;

	i = 0;
	stocks = malloc(sizeof(t_stock_str) * (ac +1));
	if (!stocks)
		return (NULL);
	while (i < ac)
	{
		stocks[i].size = ft_strlen(av[i]);
		stocks[i].str = av[i];
		stocks[i].copy = ft_strdup(av[i]);
		i++;
	}
	stocks[i].str = 0;
	stocks[i].copy = 0;
	return (stocks);
}
