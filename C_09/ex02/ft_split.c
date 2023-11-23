/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:10:59 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/16 22:20:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_issep(char ch, char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		if (ch == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_words_count(char *str, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (!ft_issep(str[i], sep))
		{
			if (str[i + 1] == '\0' || ft_issep(str[i + 1], sep))
				words++;
		}			
		i++;
	}
	return (words);
}

char	*ft_cpyword(int *next_i, char *str, char *sep)
{
	char	*dest;
	int		i;
	int		j;
	int		w_size;

	i = 0;
	j = 0;
	w_size = 0;
	while (str[i] != '\0' && ft_issep(str[i], sep))
		i++;
	while (str[i + w_size] != '\0' && !ft_issep(str[i + w_size], sep))
		w_size++;
	dest = malloc(sizeof(char *) * (w_size + 1));
	if (!dest)
		return (0);
	dest[w_size] = '\0';
	while (j < w_size)
	{
		dest[j] = str[i + j];
		j++;
	}
	*next_i += w_size + i;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		*pindex;
	int		i;
	int		index;
	int		words_count;

	i = 0;
	index = 0;
	words_count = ft_words_count(str, charset);
	pindex = &index;
	if (!str || !charset)
		return (NULL);
	output = malloc(sizeof(char **) * (words_count + 1));
	if (!output)
		return (NULL);
	output[words_count] = 0;
	if (words_count == 0)
		return (output);
	while (i < words_count)
	{	
		output[i] = ft_cpyword(pindex, &str[index], charset);
		i++;
	}
	return (output);
}

// #include <stdio.h> //DELETE
// int main(void)
// {
// 	char str0[] = "~-Ab~ABC---~cc~";
// 	char charset0[] = "~-";
// 	printf("w: %s, s: %s \n", str0, charset0);
// 	char **out = ft_split(str0, charset0);
// 	if(!out)
// 	{
// 		printf("NULL");
// 		return (0);	
// 	}
// 	int i = 0;
// 	while (out[i] != 0)
// 	{
// 		printf("out: %s\n", out[i]);
// 		free(out[i]);
// 		i++;
// 	}
// 	free(out);	
// 	return (0);
// }