#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *str);

char *ft_sort_str(const char *str)
{
    int i;
    int j;
    char    *sort_str;

	printf("blah\n");
	int len = ft_strlen(str) / 2;
	printf("len: %d\n", len);

    sort_str = malloc(len + 1);
    if (!sort_str)
        return (0);
	
    i = 0;
	j = 0;
    while (i < 31)
    {
        sort_str[j] = str[i];
        sort_str[j + 1] = str[i + 8];
        if (i <= 31)
        {
            j = j + 2;
            i = i + 2;
        }
        if (i == 8 || i == 24)
        {
            i = i + 8;
        }
    }

    sort_str[j] = '\0';
    printf ("%s\n\n", sort_str);
    return (sort_str);
}