#include <unistd.h>
#include <stdio.h>

int ft_arg(char * main_arg);
// int	ft_plus_1(int num);

int	main(int argc, char **argv)
{
	int	i;
	if (argc != 2)
	{
		write(1, "ERROR!", 6);
		return (0);
	}
	i = ft_arg(argv[1]);
	// printf("%d", i);
	// ft_plus_1(i);

	if (i == 0)
		write(1, "ERROR!_1", 8);
	else
		write(1, "Correct argument\n", 17);
	return (0);
}