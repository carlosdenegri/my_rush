/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:40:27 by cadenegr          #+#    #+#             */
/*   Updated: 2023/06/16 11:13:00 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (!(c >= 'a' && c <= 'z')
		&& !(c >= 'A' && c <= 'Z'))
		return (0);
	return (1);
}

/*
int	main()
{
	int n = ft_isalpha(" blah");
	printf ("%i\n", n);
	return(0);
}*/
