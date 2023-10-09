#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char *str);
char *ft_strncpy(char *dest, const char *src, int start, int n);
int	ft_check_row(char *str, char *substr, int i);
int	ft_check_col(char *str, char *substr, int i, char **ret2);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_results(char *res, int position);
char	*ft_strnchr(const char *s, int c, int n, size_t start);

// int	ft_get_pointer_row(char *str, char *ptr)	
// {
// 	const char *row_ptr;
// 	row_ptr = (ft_strnstr(str, ptr, ft_strlen(str)));
// 	int n = ft_strlen(str) - (row_ptr - str);
// 	return (n);
// }

int extract_rows(char *str, int start) 
{
	static int place;
	static int count;
	int len;
	int a;
	int b;
	int c;
	int d;
	int i;

	i = 0;
	place = start;
	len = ft_strlen(str);
    if (place >= len)
        return (0);
    char substr[5];
    ft_strncpy(substr, str, place, 4);
    substr[4] = '\0';
	// printf("%s\n", substr);
	// printf("%d\n", place);
	while (str[i])
	{
		if (str[i] == 'A')
			a = i; 
		if (str[i] == 'B')
			b = i;
		if (str[i] == 'C')
			c = i;
		if (str[i] == 'D')
			d = i;
		i++;
	}

	if (place < a)
		count = count + ft_check_row(str, substr, 0);
	if (place > a && place < b)
		count = count + ft_check_row(str, substr, 1);
	if (place > b && place < c)
		count = count + ft_check_row(str, substr, 2);
	if (place > c && place < d)
		count = count + ft_check_row(str, substr, 3);

    if (str[place + 4] < str[d])
    	extract_rows(str, place + 4);
	else
		printf("\n\n");
	// ft_pointer(count);
	return (count);
}

int extract_cols(char *str, int start)
{
	static int place;
	static int count;
	char *ret;
	int len;
	int e;
	int f;
	int g;
	int i;

	place = start;
	len = ft_strlen(str);
    if (start >= len)
        return (0);
    char substr[5];
    ft_strncpy(substr, str, start, 4);
    substr[4] = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == 'E')
			e = i; 
		if (str[i] == 'F')
			f = i;
		if (str[i] == 'G')
			g = i;
		i++;
	}
	// printf("%s\n", substr);
	// printf("%d\n", place);

	ret = NULL;
	if (place < e)
		count = count + ft_check_col(str, substr, 0, &ret);
	if (place > e && place < f)
		count = count + ft_check_col(str, substr, 1, &ret);
	if (place > f && place < g)
		count = count + ft_check_col(str, substr, 2, &ret);
	if (place > g && place != '\0')
		count = count + ft_check_col(str, substr, 3, &ret);
	if (ret)
	{
		printf("ret: %s\n", ret);
		i = len - (ft_strnchr(ret, 'E', len, 0) - ret);
		i = i - 4;
		
	}



    if (str[place + 4] != '\0')
	    extract_cols(str, place + 4);
	else
		printf("\n\n");
	return (count);
}