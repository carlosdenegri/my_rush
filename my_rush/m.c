# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int ft_valid_arg(const char *arg);
char *ft_sort_str(char *str);
int ft_poss(char *str);

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

//    ft_sort_str(argv[1]);
    char *sorted;

    sorted = ft_sort_str(argv[1]); 
    ft_poss(sorted);
 //   free (sorted);
    return (0);
}