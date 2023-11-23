/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:17:42 by amehrotr          #+#    #+#             */
/*   Updated: 2023/01/29 17:20:14 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_series(int a[], int n);
void	ft_putchar(char c);
void	ft_repeat(int a[], int i, int n);
int		ft_verify2print(int a[], int n);
void	ft_print_combn(int n);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_repeat(int a[], int i, int n)
{
	if (i == (n - 1))
	{
		a[i] = '0';
		while (a[i] <= '9')
		{
			if (n == 9 && a[0] > '1')
				break ;
			ft_series(a, n);
			a[i]++;
		}
	}	
	else
	{
		a[i] = '0';
		while (a[i] <= '9')
		{
			ft_repeat(a, (i + 1), n);
			a[i]++;
		}
	}
}

int	ft_verify2print(int a[], int n)
{
	int	f;
	int	i;

	f = 1;
	i = 0;
	while (i < n -1)
	{
		if (!(a[i] < a[i + 1]))
			f = 0;
		i++;
	}
	return (f);
}

void	ft_series(int a[], int n)
{
	int	i;
	int	f;

	i = 0;
	f = ft_verify2print(a, n);
	if (f == 1)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(a[i]);
			i++;
		}
		if (a[0] != '9' - n + 1)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
}

void	ft_print_combn(int n)
{
	int	a[9];

	ft_repeat(a, 0, n);
}
