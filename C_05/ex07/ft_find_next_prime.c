/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:00:43 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/08 21:10:42 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long	i;
	int		f;

	if (nb < 2)
		return (2);
	while (1)
	{
		f = 0;
		i = 2;
		while ((i * i) <= nb)
		{
			if ((nb % i) == 0)
			{
				f = 1;
				break ;
			}
			i++;
		}
		if (f == 0)
			return (nb);
		else
			nb++;
	}
}
