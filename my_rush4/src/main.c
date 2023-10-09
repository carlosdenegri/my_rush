/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:01:09 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/05 16:01:12 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "ERROR!", 6);
		return (0);
	}
	i = ft_arg(argv[1]);

	if (i == 0)
		write(1, "ERROR!_1", 8);
	else
		write(1, "Correct argument\n", 17);
	return (0);
}
