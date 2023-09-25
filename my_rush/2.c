#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *str);

char *ft_sort_str(char *str)
{
    int i;
    int j;
    char    *sort_str;

    sort_str = malloc((ft_strlen(str) / 2) + 1);
    if (!sort_str)
        return (0);

    i = 0;
    while (i < 31)
    {
        sort_str[j] = str[i];
        sort_str[j + 1] = str[i + 8];
        if (i < 31)
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
