/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:33:28 by cadenegr          #+#    #+#             */
/*   Updated: 2023/03/26 22:33:36 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc != 2)
	{
		write (1, "Error\n", 5);
		return (1);
	}
	while (j < 31)
	{
		if ((argv[1][j] < 49 || argv[1][j] > 52) && argv[1][j] != 32)
		{
			write(1, "Error\n", 5);
			return (1);
		}
		else
		{
			if (argv[1][j] >= 49 && argv[1][j] <= 52 &&
				argv[1][j + 1] != 32 && j != 30)
			{
				write(1, "eRror\n", 5);
				return (1);
			}
			if (argv[1][j] == 32 && (argv[1][j + 1] < 49 ||
				argv[1][j + 1] > 52))
			{
				write(1, "error\n", 5);
				return (1);
			}
		}
		j++;
	}
	while (i < 23)
	{
		if (i == 6)
			i = i + 10;
		else
			i = i + 2;
	}
}
