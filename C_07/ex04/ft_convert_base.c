/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:30:48 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/15 18:10:40 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*get_new_num(long nbr, char *base, int b);
long	get_num(char *str, char *base, int b, long num);
void	ft_rev_str(char *str);
int		ft_malloc(char **new_nbr, int *sign, long *nbr);

int	ft_check_base(char *base, int b)
{
	int	i;
	int	j;

	i = 0;
	while (base [i] != 0)
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		else
		{
			j = i + 1;
			while (j < b)
			{
				if (base[i] == base[j])
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
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

long	ft_atoi_base(char *str, char *base, int b)
{
	long	nbr;
	char	num_str[200];

	nbr = 0;
	ft_atoi_str(str, base, &num_str[0]);
	if (num_str[0] == '\0')
		return (0);
	nbr = get_num(num_str, base, b, nbr);
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	atoi;
	char	*new_nbr;
	int		bf;
	int		bt;

	bf = 0;
	bt = 0;
	while (base_from[bf] != '\0')
		bf++;
	while (base_to[bt] != '\0')
		bt++;
	if ((ft_check_base(base_from, bf))
		|| (ft_check_base(base_to, bt)) || (bf < 2) || (bt < 2))
		return (0);
	atoi = ft_atoi_base(nbr, base_from, bf);
	if (((atoi > 2147483647) || (atoi < -2147483648)))
		return (0);
	new_nbr = get_new_num(atoi, base_to, bt);
	if (new_nbr == NULL)
		return (0);
	return (new_nbr);
}
