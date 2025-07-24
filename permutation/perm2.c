/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perm2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:48:12 by ibayandu          #+#    #+#             */
/*   Updated: 2025/07/24 19:39:13 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	ft_strlen;

	ft_strlen = 0;
	while (str[ft_strlen])
		ft_strlen++;
	return (ft_strlen);
}

void	ft_swap(char *str1, char *str2)
{
	char	tmp;

	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}

void	sort_arg(char *arg)
{
	int	arglen;
	int	j;

	arglen = ft_strlen(arg);
	while (arglen--)
	{
		j = 0;
		while (arg[j + 1])
		{
			if (arg[j] > arg[j + 1])
				ft_swap(arg + j, arg + j + 1);
			j++;
		}
	}
}

void	permute(char *str, int start, int end)
{
	int	i;

	if (start == end)
		puts(str);
	else
	{
		i = start;
		while (i < end)
		{
			sort_arg(str + start);
			ft_swap(str + start, str + i);
			permute(str, start + 1, end);
			ft_swap(str + start, str + i);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	permute(argv[1], 0, ft_strlen(argv[1]));
	return (0);
}
