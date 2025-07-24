/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibayandu <ibayandu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 04:56:27 by ibayandu          #+#    #+#             */
/*   Updated: 2025/07/18 18:39:19 by ibayandu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_available(int n, char cb[n+1][n+1], int x, int y)
{
	int i, j;

	for (i = 0; i < y; i++)
		if (cb[i][x] == '1')
			return 0;
	for (i = y - 1, j = x - 1; i >= 0 && j >= 0; i--, j--)
		if (cb[i][j] == '1')
			return 0;
	for (i = y - 1, j = x + 1; i >= 0 && j <= n; i--, j++)
		if (cb[i][j] == '1')
			return 0;

	return 1;
}

void print_solution(int n, char cb[n+1][n+1])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cb[i][j] == '1')
			{
				if (i == n-1)
					printf("%d\n",j);
				else
					printf("%d ",j);
				break;
			}
		}
	}
}

void n_queen(int n, char cb[n+1][n+1],int index)
{
	if (index == n)
	{
		print_solution(n,cb);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (is_available(n,cb,i,index))
		{
			cb[index][i] = '1';
			n_queen(n, cb, index+1);
			cb[index][i] = '0';
		}
	}
}

int	main(int argc, char **argv)
{
	int		n;

	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	char	cb[n + 1][n + 1];
	cb[n][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j == n)
				cb[i][j] = 0;
			else
				cb[i][j] = '0';
		}
	}
	n_queen(n,cb,0);
}
