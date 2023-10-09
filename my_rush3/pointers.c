#include <stdlib.h>

size_t	ft_strlen(char *str);    

int	ft_get_pointer_row(char *str, char *ptr)	
{
	const char *row_ptr;
	row_ptr = (ft_strnstr(str, ptr, ft_strlen(str)));
	return (row_ptr);
}


	int	start;
	extract_rows(str, 0);
	start = 0;
	while (str[start] != 'D')
		start++;
	start = start + 4;
	extract_cols(str, start);

			if (index == 0)
			ft_results(substr, 68);
		if (index == 1)
			ft_results(substr, 69);
		if (index == 2)
			ft_results(substr, 70);
		if (index == 3)
			ft_results(substr, 71);