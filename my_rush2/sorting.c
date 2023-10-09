#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char *ft_set_str_1(const char format, char *stat);
char *ft_set_str_2(const char format, char *stat);
char *ft_set_str_3(const char format, char *stat);
char *ft_set_str_4(const char format, char *stat);
void	*ft_calloc(size_t nmemb, size_t size);
char    *ft_space_between(char *stat, int count);

int ft_poss(char *str)
{
    int i;
    char *stat;

    stat = ft_calloc(630, 1);
    i = 0;
    while (i <= 16)
    {
        if (i % 2 == 1)
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
    printf ("%s", stat);
    free (stat);
    stat = NULL;
    free (str);
    str = NULL;
    return (i);
}