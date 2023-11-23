/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:18:44 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/06 21:03:10 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	num;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num = nb * ft_recursive_power(nb, power - 1);
	return (num);
}
