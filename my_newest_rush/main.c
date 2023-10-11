#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str[i])
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *s, char *buffer)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s)
// 	{
// 		s = (char *)malloc(1 * sizeof(char));
// 		s[0] = '\0';
// 	}
// 	if (!s || !buffer)
// 		return (NULL);
// 	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buffer)) + 1));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (s)
// 		while (s[++i] != '\0')
// 			str[i] = s[i];
// 	while (buffer[j] != '\0')
// 		str[i++] = buffer[j++];
// 	str[ft_strlen(s) + ft_strlen(buffer)] = '\0';
// 	free(s);
// 	return (str);
// }



void generatePermutations(char *sequence, int start, int end, char *arg, char *my_string);
void    extract_rows(char *str, int start, char *line);
char    *extract_cols(char *str, int start, char *line);

int main()
{
    int i = 0;
    int j = 0;
    char argument[] = "21142322223241123";
    char arg[3];
    char sequence[] = "1234";
    char separator = 65;
    char my_string[1000] = "";
    char str[1000] = "";
    char final[100] = "";
    int length = strlen(sequence);
    int len;

    // int result = ft_visible_nums();
    // int result2 = ft_rev_visible_nums();

    // printf("count: %d\n", result2);
    // printf("reversed %d\n", result);

    // printf("All permutations of %s are:\n", sequence);
    while (argument[i])
    {
        if (j < 2)
        {
            arg[j] = argument[i];
            j++;
            i++;
        }
        if (j == 2)
        {
            arg[j] = 0;
            j = 0;
            printf ("%s\n", arg);
            generatePermutations(sequence, 0, length - 1, arg, my_string);
            len = strlen(my_string);
            while (j < 4)
            {
                my_string[len] = separator;
                len++;
                j++;
            }
            my_string[len] = '\0';
            separator = separator + 1;
            j = 0;
        }
    }
    printf ("\n%s\n", my_string);
    // str = my_string;
    extract_rows(my_string, 0, str);
    printf ("\n%s\n", str);
	int start = 0;
    while (my_string[start] != 'D')
		start++;
	start = start + 4;
    extract_cols(my_string, start, str);
    printf ("\n%s\n", str);
	start = 0;
    while (str[start] != 'D')
		start++;
	start = start + 4;
    extract_rows(str, 0, final);
    extract_cols(str, start, final);
    printf("\n%s\n", final);
    memset(str, 0, sizeof(str));
	start = 0;
    while (final[start] != 'D')
		start++;
	start = start + 4;
    extract_rows(final, 0, str);
    extract_cols(final, start, str);
    printf("\n%s\n", str);


    return 0;
}

// 4231 4312 4132 3214 3124 1432 2431 3421 1243 1342 2341 1423 2143 2413 3241 3142 3412 1234