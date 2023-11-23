/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:34:48 by coder             #+#    #+#             */
/*   Updated: 2023/02/16 19:05:45 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_check_seprator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_sub_string(char **pos, char *charset, int *sub_str_len)
{
	int		i;
	char	*str_i;

	*sub_str_len = 0;
	str_i = 0;
	i = 0;
	while (pos[0][i])
	{
		if (ft_check_seprator(pos[0][i], charset) && str_i != 0)
		{
			*pos = str_i + *sub_str_len;
			return (str_i);
		}
		else if (!(ft_check_seprator(pos[0][i], charset)) && str_i == 0)
			str_i = &pos[0][i];
		if (!(ft_check_seprator(pos[0][i], charset)))
			*sub_str_len = *sub_str_len + 1;
		i++;
	}
	*pos = str_i + *sub_str_len;
	if (sub_str_len == 0)
		return (0);
	return (str_i);
}

char	**ft_allocate_mem(char *str, char *charset)
{
	int		n_str;
	char	**strs;
	int		sub_str_len;
	char	*pos;
	int		i;

	n_str = 0;
	i = 0;
	sub_str_len = 0;
	pos = str;
	while (str[i] != '\0')
	{
		if (!ft_check_seprator(str[i], charset))
		{
			if (str[i + 1] == '\0' || ft_check_seprator(str[i + 1], charset))
				n_str++;
		}			
		i++;
	}
	while (ft_get_sub_string(&pos, charset, &sub_str_len))
		n_str++;
	strs = (char **)malloc(sizeof(char *) * (n_str + 1));
	if (!strs)
		return (0);
	return (strs);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0' && i != n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		sub_str_len;
	char	*sub_str;
	char	*pos;
	int		i;

	i = 0;
	if (str[i] == '\0' || charset[i] == '\0')
		return (0);
	strs = ft_allocate_mem(str, charset);
	if (!strs)
		return (0);
	pos = str;
	sub_str = ft_get_sub_string(&pos, charset, &sub_str_len);
	while (sub_str)
	{
		strs[i] = (char *)malloc(sizeof(char) * (sub_str_len + 1));
		if (!strs[i])
			return (0);
		ft_strncpy(strs[i], sub_str, sub_str_len);
		i++;
		sub_str = ft_get_sub_string(&pos, charset, &sub_str_len);
	}
	strs[i] = 0;
	return (strs);
}
