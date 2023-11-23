/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehrotr <amehrotr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:05:54 by amehrotr          #+#    #+#             */
/*   Updated: 2023/02/11 20:08:49 by amehrotr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_str(int argc, char **argv)
{
	char	*temp;
	int		i;
	int		j;
	int		f;

	j = 1;
	while (j < argc - 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			f = ft_strcmp(argv[i], argv[i + 1]);
			if (f > 0)
			{
				temp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = temp;
			}
			i++;
			f = 0;
		}
		j++;
	}	
}

void	ft_print_param(char **str)
{
	int	i;

	i = 1;
	while (str[i] != 0)
	{
		ft_putstr(str[i]);
		ft_putstr("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc;
	if (i > 1)
	{
		while (i != 2)
		{
			ft_sort_str(argc, argv);
			i--;
		}
		ft_print_param(argv);
	}
	return (0);
}
