/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leon.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leon Carlos Denegri Haustein               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:49:21 by cadenegr          #+#    #+#             */
/*   Updated: 2023/08/02 13:50:02 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void starwars(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main()
{
	starwars("Komander Rex und seine Soldaten kaempfen gegen die Droieden mit Anakin Skywalker.");
	return(0);
}
