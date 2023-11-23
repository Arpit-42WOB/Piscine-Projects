/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:45:21 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/15 15:54:55 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		l;
	char	*dup_str;

	l = 0;
	if (src == NULL)
		return (0);
	while (src[l] != '\0')
		l++;
	dup_str = (char *)malloc(sizeof(char) * (l + 1));
	if (dup_str == NULL)
		return (0);
	i = 0;
	while (i <= l)
	{
		dup_str[i] = src[i];
		i++;
	}
	return (dup_str);
}
