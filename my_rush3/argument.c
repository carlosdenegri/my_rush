#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
int	ft_isdigit(int c);
int	ft_isspace(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int ft_sorting(char *str);

int	ft_sort_arg(char *str)
{
	int	i;
	int	j;
	int	len;
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
	// ft_sorting(sort_str);
	return (ft_sorting(sort_str));
}

int ft_arg_format(char *str)
{
	int i;
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
	// ft_sort_arg(str);
	return (ft_sort_arg(str));
}

int ft_arg(char * main_arg)
{
	int len;

	len = ft_strlen(main_arg);
	if (len != 31)
		return (0);
	return(ft_arg_format(main_arg));
}