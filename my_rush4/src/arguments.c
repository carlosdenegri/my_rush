/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadenegr <cadenegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:02:34 by cadenegr          #+#    #+#             */
/*   Updated: 2023/10/05 16:07:02 by cadenegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sort_arg(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*sort_str;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	sort_str = ft_calloc(600, 1);
	while (i < len)
	{
		sort_str[j] = str[i];
		sort_str[j + 1] = str[i + 8];
		i = i + 2;
		j = j + 2;
		if (i == 8 || i == 24)
			i = i + 8;
	}
	sort_str[j] = '\0';
	printf("%s\n\n", sort_str);
	return (ft_sorting(sort_str));
}

char	*ft_arg_format(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_isdigit(str[i]))
			i = i + 2;
		else
			return (0);
	}
	i = 1;
	while (i < len)
	{
		if (ft_isspace(str[i]) && i != len)
			i = i + 2;
		else
			return (0);
	}
	return (ft_sort_arg(str));
}

char	*ft_arg(char *main_arg)
{
	int	len;

	len = ft_strlen(main_arg);
	if (len != 31)
		return (0);
	return (ft_arg_format(main_arg));
}
