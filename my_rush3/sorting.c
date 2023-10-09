#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char *ft_set_str_1(const char format, char *stat);
char *ft_set_str_2(const char format, char *stat);
char *ft_set_str_3(const char format, char *stat);
char *ft_set_str_4(const char format, char *stat);
void	*ft_calloc(size_t nmemb, size_t size);
char    *ft_space_between(char *stat, int count);
int extract_rows(char *str, int start);
int extract_cols(char *str, int start);

int ft_sorting(char *str)
{
    int a;
	int b;
	int i;
    char *stat;
	int	start;

    stat = ft_calloc(650, 1);
    i = 0;
    while (i <= 16)
    {
        if (i % 2 != 0)
        {
            if (str[i - 1] == '1')
                stat = ft_set_str_1(str[i], stat);
            else if (str[i - 1] == '2')
                stat = ft_set_str_2(str[i], stat);
            else if (str[i - 1] == '3')
                stat = ft_set_str_3(str[i], stat);
            else if (str[i - 1] == '4')
                stat = ft_set_str_4(str[i], stat);            
        }
        else if (i != 0 && i % 2 == 0 && i != 16)
            stat = ft_space_between(stat, i);
        i++;
    }
	printf ("%s\n\n", stat); //here I send my string

	// extract_rows(stat, 0);
	a = extract_rows(stat, 0);
	start = 0;
	while (stat[start] != 'D')
		start++;
	start = start + 4;
	// extract_cols(stat, start);
	b = extract_cols(stat, start);

    free (stat);
    stat = NULL;
    free (str);
    str = NULL;
    return (a + b);
}