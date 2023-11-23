/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:32:19 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/11 19:39:58 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbrn(long nb, int b, char *base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbrn(-nb, b, base);
	}
	else if (nb >= b)
	{
		ft_putnbrn(nb / b, b, base);
		ft_putnbrn(nb % b, b, base);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

int	ft_check_base(char *base, int b)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	f = 0;
	while (base [i] != 0)
	{
		if (base[i] == '-' || base[i] == '+'
			|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
				f = 1;
		else
		{
			j = i + 1;
			while (j < b -1)
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

void	ft_putnbr_base(int nbr, char *base)
{
	int	b;
	int	f;

	b = 0;
	while (base[b] != 0)
		b++;
	f = ft_check_base(base, b);
	if (f == 0 && b > 1)
		ft_putnbrn(nbr, b, base);
}
