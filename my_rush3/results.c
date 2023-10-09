#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_last_str(char *resu, char *str, int position, int index);
int extract_rows(char *str, int start);
int extract_cols(char *str, int start);

// void	ft_plus_1(int num)
// {
// 	int i;
// 	i = num;

// 	return (i);

// }

char	*ft_results(char *res, int position, int index)
{
	static int i;
	static int count;
	int j;
	static char *results = NULL;

	if (!res)
		return (NULL);

	if (results == NULL)
		results = ft_calloc (999, 1);
	j = 0;
	while (res[j])
		results[i++] = res[j++];
	j = 0;
	while (j < 4)
	{
		results[i++] = position + index;
		j++;
	}
	results[i] = '\0';
	count++;
	// printf("%s\n", results);
	// liberar = results;
	// free (liberar);
	// liberar = NULL;
	// if (ft_plus_1(0) == count)

	// printf("%s\n", results);
	
	return(results);
}