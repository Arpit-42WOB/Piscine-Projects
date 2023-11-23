/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:58:05 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/11 14:59:40 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);
void	ft_print_address(int n, char *p);
int		ft_print_hexa(int i, int size, char *p, int k);
void	ft_print_str(int i, int size, char *p);
void	*ft_print_memory(void *addr, unsigned int size);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_address(int n, char *p)
{
	long	c;
	int		i;
	char	addr[16];
	int		r;

	c = (long) &p[n];
	i = 16;
	while (i-- > 0)
	{
		r = c % 16;
		c = c / 16;
		if (r < 10)
			addr[i] = (r + 48);
		else
			addr[i] = (r + 87);
	}
	i = 0;
	while (i++ < 16)
		ft_putchar(addr[i - 1]);
	ft_putchar(':');
	ft_putchar(' ');
}

int	ft_print_hexa(int i, int size, char *p, int k)
{
	int	j;

	j = 0;
	while ((j < 16) && (i + j) < size)
	{
		k = p[i + j];
		if (k < 0)
			k = k + 256;
		if ((k / 16) < 10)
			ft_putchar((k / 16) + 48);
		else
			ft_putchar((k / 16) + 87);
		if ((k % 16) < 10)
			ft_putchar((k % 16) + 48);
		else
			ft_putchar((k % 16) + 87);
		if ((j++ % 2) != 0)
			ft_putchar(' ');
	}
	return (j);
}

void	ft_print_str(int i, int size, char *p)
{
	int	j;

	j = 0;
	while (((j < 16) && (i + j) < size))
	{
		if ((p[i + j] >= 32) && (p[i + j] <= 126))
			ft_putchar(p[i + j]);
		else
			ft_putchar('.');
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*c;
	int				j;

	c = (char *) addr;
	i = 0;
	while (i < size)
	{
		ft_print_address(i, addr);
		j = ft_print_hexa(i, size, addr, 0);
		while (j++ < 16)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			if ((j % 2) == 0)
				ft_putchar(' ');
		}
		ft_print_str(i, size, addr);
		ft_putchar('\n');
		i = i + 16;
	}
	return (addr);
}
