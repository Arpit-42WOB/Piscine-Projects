/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:14:48 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/06 15:45:27 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	else
		return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char s1[] = {"Welcome"};
// 	char s2[] = {"Welcome   "};
// 	int r;

// 	r =	ft_strncmp(&s1[0], &s2[0], 8);
// 	printf("%d\n", r);
// 	printf("%d", strncmp(&s1[0], &s2[0], 8));
// 	return(0);
// }
