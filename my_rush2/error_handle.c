# include <unistd.h>

int ft_strlen(const char *str);
int	ft_isdigit(int c);
int ft_isspace(int c);

int ft_valid_arg(const char *str)
{
    int i;

    if (!str)
        return (1);
    if (ft_strlen(str) != 31)
    {
        write (1, "t", 1);
        return (1);
    }
    
    i = 0;
    while(str[i])
    {
        if (i % 2 == 0)
        {
            if (ft_isdigit(str[i]))
                i++;
            else
            {
                write (1, "a", 1);
                return (1);
            }
        }
        if (i < 31 && i % 2 == 1)
        {
            if (ft_isspace(str[i]))
                i++;
            else
            {
                write (1, "b", 1);
                return (1);
            }
        }
    }
    return (i);
}