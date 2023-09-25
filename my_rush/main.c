/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:11:52 by cadenegr          #+#    #+#             */
/*   Updated: 2023/07/27 17:10:44 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	*str1;
	int		index;
	int		i;

	if (argc != 2)
	{
		write(1, "Error! Must have only one argument after ./a.out!", 49);
		return (1);
	}
	str1 = (char *)malloc(17 * sizeof(char));
	if (str1 == NULL)
	{
		write(1, "Error! The argument is NULL!", 28);
		return (1);
	}
	i = 0;
	index = 0;
	while (argv[1][i] != '\0')
	{
		if (i > 30)
		{
			write(1, "Error! Argument too long!", 26);
			free(str1);
			return (1);
		}
		if (!(ft_isdigit(argv[1][0])))
		{
			write(1, "Error! The first character must be a number!", 45);
			free(str1);
			return (1);
		}
		if (argv[1][i] != ' ')
		{
			if (argv[1][i] == ' ' && argv[1][i - 1] != ' ')
			{
				write(1, "Error! Only one space", 23);
				free(str1);
				return (1);
			}
			if (argv[1][i] < '1' || argv[1][i] > '4')
			{
				write(1, "Error! Only numbers between 1 and 4!", 36);
				free(str1);
				return (1);
			}
			str1[index++] = argv[1][i];
		}
		if (argv[1][i] == ' ' && argv[1][i + 1] == ' ')
		{
			write(1, "Error! Only one space between number!", 37);
			free(str1);
			return (1);
		}
		i++;
	}
	if (index != 16)
	{
		write(1, "Error! You need 16 numbers!", 28);
		free(str1);
		return (1);
	}
	str1[index] = '\0';
	write(1, str1, ft_strlen(str1));
	free(str1);
	return (0);
}
