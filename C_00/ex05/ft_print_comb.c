/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:15:57 by amehrotr          #+#    #+#             */
/*   Updated: 2023/01/29 14:16:00 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	write_comb(char i, char j, char k);

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i < '8')
	{
		j = '1';
		while (j < '9')
		{
			k = '2';
			while (k <= '9')
			{
				write_comb(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	write_comb(char i, char j, char k)
{
	char	d;
	char	s;

	d = ',';
	s = ' ';
	if (i < j && j < k && i < k)
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
		if (i != '7' || j != '8' || k != '9')
		{
			write(1, &d, 1);
			write(1, &s, 1);
		}
	}
}
