/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:57:36 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/11 14:57:42 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = (int)str[i];
		if (c < 32 || c >= 127)
		{
			ft_putchar('\\');
			if (c < 0)
				c = (c + 256);
			if ((c / 16) < 10)
				ft_putchar((c / 16) + 48);
			else
				ft_putchar((c / 16) + 87);
			if ((c % 16) < 10)
				ft_putchar((c % 16) + 48);
			else
				ft_putchar((c % 16) + 87);
		}
		else
			ft_putchar(c);
		i++;
	}
}
