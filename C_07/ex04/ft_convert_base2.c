/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:42:22 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/16 19:05:29 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_check_in_base(char c, char *base);
int		ft_check_base(char *base, int b);
void	ft_atoi_str(char *str, char *base, char *num);
long	ft_atoi_base(char *str, char *base, int b);

void	ft_rev_str(char *str)
{
	int		i;
	int		l;
	char	temp;

	l = 0;
	while (str[l] != '\0')
		l++;
	i = 0;
	while (i < l - 1)
	{
		l--;
		temp = str[i];
		str[i] = str[l];
		str[l] = temp;
		i++;
	}
}

long	get_num(char *str, char *base, int b, long num)
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

int	ft_malloc(char **new_nbr, int *sign, long *nbr)
{
	new_nbr[0] = (char *)malloc(sizeof(char) * 40);
	if (!new_nbr)
		return (1);
	*sign = 1;
	if (*nbr == 0)
		new_nbr[0][0] = '0';
	if (*nbr < 0)
	{
		*nbr = *nbr * (-1);
		*sign = -1;
	}
	return (0);
}

char	*get_new_num(long nbr, char *base, int b)
{
	int		i;
	char	*new_nbr;
	int		sign;

	if (ft_malloc(&new_nbr, &sign, &nbr))
		return (0);
	if (new_nbr[0] == '0')
		i = 1;
	else
		i = 0;
	while (nbr > 0)
	{
		new_nbr[i] = base[nbr % b];
		nbr = nbr / b;
		i++;
	}
	if (sign == -1)
		new_nbr[i++] = '-';
	new_nbr[i] = '\0';
	ft_rev_str(new_nbr);
	return (new_nbr);
}
