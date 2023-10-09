# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

char *ft_set_str_1(const char format, char *stat)
{
    if (format == '2')
    {
        char str12[] = "41234213";
        stat = ft_strjoin(stat, str12);
    }
    else if (format == '3')
    {
        char str13[] = "423141324312";
        stat = ft_strjoin(stat, str13);
    }
    else if (format == '4')
    {
        char str14[] = "4321";
        stat = ft_strjoin(stat, str14);
    }
    else
    {
        write (1, "Impossible argument\n", 20);
        return (0);
    }
    return (stat);
}

char *ft_set_str_2(const char format, char *stat)
{
    if (format == '1')
    {
        char str21[] = "31243214";
        stat = ft_strjoin(stat, str21);
    }
    else if (format == '2')
    {
        char str22[] = "314232413412241314232143";
        stat = ft_strjoin(stat, str22);
    }
    else if (format == '3')
    {
        char str23[] = "342114322431";
        stat = ft_strjoin(stat, str23);
    }
    else
    {
        write (1, "Impossible argument\n", 20);
        return (0);
    }
    return (stat);
}

char *ft_set_str_3(const char format, char *stat)
{
    if (format == '1')
    {
        char str31[] = "132421342314";
        stat = ft_strjoin(stat, str31);
    }
    else if (format == '2')
    {
        char str32[] = "124313422341";
        stat = ft_strjoin(stat, str32);
    }
    else
    {
        write (1, "Impossible argument\n", 20);
        return (0);
    }
    return (stat);
}

char *ft_set_str_4(const char format, char *stat)
{
	if (format == '1')
    {
       char str41[] = "1234";
       stat = ft_strjoin(stat, str41);
    }
    else
    {
        write (1, "Impossible argument\n", 20);
        return (0);
    }
    return (stat);
}

char    *ft_space_between(char *stat, int count)
{
	char	*ptr;
	int		i;
	int		j;
    char end[] = "AAAABBBBCCCCDDDDEEEEFFFFGGGG";  

	if (!stat)
		return (NULL);
	ptr = ft_calloc(999, 1);
	i = 0;
	j = 0;
    count = (count - 2) * 2;
	while (stat[j])
		ptr[i++] = stat[j++];
	j = 0;
	while (j < 4)
    {
		ptr[i++] = end[count++];
        j++;
    }
	ptr[i] = '\0';
    // stat = ptr;
	// free (ptr);
	return (ptr);
}