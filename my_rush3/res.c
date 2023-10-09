# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_last_str(char * resu, char *str, int position, int index)
{
	char *res;
	int		j;

	j = 0;
	res = ft_calloc(999, 1);
	res = resu;
	while (str[j])
		res[index++] = str[j++];
	j = 0;
	while (j < 4)
	{
		res[index++] = position;
		j++;
	}
	res[index] = '\0';
	printf("%s\n", res);
	return (res);
}