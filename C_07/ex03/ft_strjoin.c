/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:03:03 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/15 16:08:05 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*get_memory(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		mem;
	char	*str;

	i = 0;
	mem = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			j++;
		mem = mem + j;
		i++;
	}
	j = 0;
	while (sep[j] != '\0')
		j++;
	mem = mem + (j * size) - 1;
	if (size <= 0)
		mem = 1;
	str = (char *)malloc(sizeof(char) * (mem + 1));
	if (!str)
		return (0);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = get_memory(size, strs, sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[k] = strs[i][j];
			k++;
			j++;
		}
		j = 0;
		while (sep[j] != '\0' && i < (size - 1))
			str[k++] = sep[j++];
		i++;
	}
	str[k] = '\0';
	return (str);
}
