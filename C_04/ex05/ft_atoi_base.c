/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:40:15 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/11 19:40:48 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_check_base(char *base, int b)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	f = 0;
	while (base [i] != 0)
	{
		if (base[i] == '-' || base[i] == '+')
				f = 1;
		else
		{
			j = i + 1;
			while (j < b)
			{
				if (base[i] == base[j])
					f = 1;
				j++;
			}
		}
		i++;
	}
	return (f);
}

int	ft_check_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_num(char *str, char *base, int b, int num)
{
	int	f;
	int	i;
	int	j;

	f = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_check_in_base(str[i], base))
		{
			f = 1;
			j = 0;
			while (str[i] != base[j])
				j++;
			num = (num * b) + j;
			i++;
		}
		if (f == 1)
			break ;
		i++;
	}
	if (str[0] == '-')
		num = num * (-1);
	return (num);
}

void	ft_atoi_str(char *str, char *base, char *num)
{
	int	i;
	int	j;
	int	minus;

	i = 0;
	j = 0;
	minus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus++;
	if (minus % 2 == 1)
		num[j++] = '-';
	while (ft_check_in_base(str[i], base))
		num[j++] = str[i++];
	num[j] = '\0';
}

int	ft_atoi_base(char *str, char *base)
{
	int		b;
	int		f;
	int		nbr;
	char	num_str[200];

	b = 0;
	nbr = 0;
	while (base[b] != 0)
		b++;
	f = ft_check_base(base, b);
	if (f == 1 || b < 2)
		return (0);
	ft_atoi_str(str, base, &num_str[0]);
	nbr = get_num(num_str, base, b, nbr);
	return (nbr);
}
