/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:49:43 by ibayandu          #+#    #+#             */
/*   Updated: 2025/07/18 11:18:08 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE /* See feature_test_macros(7) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = (char)c;
	return (s);
}

int	main(int argc, char **argv)
{
	char	*haystack;
	char	*needle;
	char	buffer;
	int		is_readed;
	int		i;
	char	*founded;

	if (argc != 2)
		return (1);
	haystack = calloc(1, 1);
	needle = argv[1];
	is_readed = read(0, &buffer, 1);
	i = 0;
	while (is_readed > 0)
	{
		haystack[i++] = buffer;
		haystack = realloc(haystack, i + 1);
		haystack[i] = 0;
		is_readed = read(0, &buffer, 1);
	}
	founded = haystack;
	while ((founded = memmem(founded, strlen(founded), needle, strlen(needle))))
	{
		ft_memset(founded, '*', strlen(needle));
		founded = founded + strlen(needle);
	}
	printf("%s", haystack);
}
