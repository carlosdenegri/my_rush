# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int ft_valid_arg(const char *arg);
char *ft_sort_str(const char *str);
int ft_poss(char *str);
void extract_rows(char *str, size_t start);
void extract_cols(char *str, size_t start);

int main(int argc, char **argv)
{
    int i;

    if (argc != 2)
    {
        write (1, "ERROR!", 6);
        return (1);
    }
    i = ft_valid_arg(argv[1]);

    if (i == 1)
    {
        write (1, "ERROR!", 6);
        return (1);
    }

	ft_sort_str(argv[1]);
	char *sorted;
	int start;

    sorted = ft_sort_str(argv[1]); 
    ft_poss(sorted);

	extract_rows(sorted, 0);

	start = 0;
	while (sorted[start] != 'D')
		start++;
	start = start + 4;
	extract_cols(sorted, start);

	// free (sorted);
    return (0);
}