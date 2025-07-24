/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 07:35:49 by ibayandu          #+#    #+#             */
/*   Updated: 2025/07/18 10:13:03 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_val(char *str)
{
	int	opened;
	int	closed;

	opened = 0;
	closed = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '(')
			opened++;
		else if (str[i] == ')')
		{
			if (opened > 0)
				opened--;
			else
				closed++;
		}
	}
	return (opened + closed);
}

void	rip(char *av, int must_count, int fixed_count, int pos)
{
	int	c;

	if (must_count == fixed_count && !is_val(av))
	{
		puts(av);
		return ;
	}
	for (int i = pos; av[i]; i++)
	{
		if (av[i] == '(' || av[i] == ')')
		{
			c = av[i];
			av[i] = ' ';
			rip(av, must_count, fixed_count + 1, i);
			av[i] = c;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	rip(av[1], is_val(av[1]), 0, 0);
}