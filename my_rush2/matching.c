#include <stddef.h>
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	s1_ptr = (const unsigned char *)s1;
	s2_ptr = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*big_ptr;
	const char	*little_ptr;
	size_t		i;

	big_ptr = big;
	little_ptr = little;
	i = 0;
	if (little_ptr[0] == '\0')
		return ((char *)big_ptr);
	while (big_ptr[i] != '\0' && i < len)
	{
		if (big_ptr[i] == little_ptr[0])
		{
			if (ft_memcmp(&big_ptr[i], little_ptr, ft_strlen(little_ptr)) == 0)
			{
				if (i + ft_strlen(little_ptr) <= len)
					return ((char *)&big_ptr[i]);
			}
		}
		i++;
	}
	return (NULL);
}

char *ft_strncpy(char *dest, const char *src, int start, int n) {
    char *original_dest = dest; // Store the original destination pointer
	int i;
    // Copy up to n characters from src to dest
    i = 0;
	while (i < n && src[i + start] != '\0')
	{
        dest[i] = src[i + start];
		i++;
    }
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
   // Fill the remaining space in dest with null characters
    return original_dest; // Return a pointer to the beginning of the destination string
}

#include <stddef.h>

// char *ft_strnchr(const char *str, int c, size_t n, size_t start)
// {
// 	str += start;
//     while (*str != '\0' && n > 0) {
//         if (*str == c) {
//             return (char *)str;
//         }
//         str = str + 4;
//         n--;
//     }
//     return NULL;
// }
char	*ft_strnchr(const char *s, int c, int n, size_t start)
{
	int	i;

	i = 0 + start;
	while (s[i] != '\0' && s[i] != (char)c && i <= n)
		i = i + 4;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

int	ft_strncmp(const char *s1, char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_print_check(const char *result, char *str)
{
    if (result != NULL) 
	    printf("Substring found at position: %ld\n", result - str);
    else
	    printf("Substring not found.\n");
}

void	ft_check_row(char *str, char *substr, int i)
{
    char *first_ptr = "DDDD";
    char *second_ptr = "EEEE";
    char *third_ptr = "FFFF";
    char *fourth_ptr = "GGGG";

	const char *first_row = (ft_strnstr(str, first_ptr, ft_strlen(str)));
	const char *second_row = (ft_strnstr(str, second_ptr, ft_strlen(str)));
	const char *third_row = (ft_strnstr(str, third_ptr, ft_strlen(str)));
	const char *fourth_row = (ft_strnstr(str, fourth_ptr, ft_strlen(str)));
	int w = ft_strlen(str) - (fourth_row - str);
	int x = ft_strlen(str) - (third_row - str);
	int y = ft_strlen(str) - (second_row - str);
	int z = ft_strlen(str) - (first_row - str);
	// printf("%d\n", (z - y));
	// printf("%d\n", (y - x));
	// printf("%d\n", (x - w));
	// printf("%d\n", w);

	char *result1 = ft_strnchr(first_row, substr[0], z - y, i);
	char *result2 = ft_strnchr(second_row, substr[1], y - x, i);
	char *result3 = ft_strnchr(third_row, substr[2], x - w, i);
	char *result4 = ft_strnchr(fourth_row, substr[3], w, i);

	if (result1 != NULL && result2 != NULL && result3 != NULL && result4 != NULL)
	{
		printf("Substring: %s Level:%d\n", substr, i);
		ft_print_check(result1, str);
		ft_print_check(result2, str);
		ft_print_check(result3, str);
		ft_print_check(result4, str);
	}
}

void	ft_check_col(char *str, char *substr, int i)
{
	char *first_col_ptr = "AAAA";
	char *second_col_ptr = "BBBB";
	char *third_col_ptr = "CCCC";
	char *fourth_col_ptr = "DDDD";

	const char *first_col = (ft_strnstr(str, first_col_ptr, ft_strlen(str)));
	const char *second_col = (ft_strnstr(str, second_col_ptr, ft_strlen(str)));
	const char *third_col = (ft_strnstr(str, third_col_ptr, ft_strlen(str)));
	const char *fourth_col = (ft_strnstr(str, fourth_col_ptr, ft_strlen(str)));
	int a = ft_strlen(str) - (first_col - str);
	int b = ft_strlen(str) - (second_col - str);
	int c = ft_strlen(str) - (third_col - str);
	int d = ft_strlen(str) - (fourth_col - str);
	int A = (ft_strlen(str) - a);
	// printf("%d\n", (a - b));
	// printf("%d\n", (b - c));
	// printf("%d\n", (c - d));
	char *result1 = ft_strnchr(str, substr[0], A, i);
	char *result2 = ft_strnchr(first_col, substr[1], a - b, i);
	char *result3 = ft_strnchr(second_col, substr[2], b - c, i);
	char *result4 = ft_strnchr(third_col, substr[3], c - d, i);

	if (result1 != NULL && result2 != NULL && result3 != NULL && result4 != NULL)
	{
		printf("Substring: %s Level:%d\n", substr, i);
		ft_print_check(result1, str);
		ft_print_check(result2, str);
		ft_print_check(result3, str);
		ft_print_check(result4, str);
	}
}

void extract_rows(char *str, size_t start) 
{
    // Add a base case to stop recursion
    if (start >= ft_strlen(str))
        return;

    char substr[5]; // To store the extracted 4 digits
    ft_strncpy(substr, str, start, 4);
    substr[4] = '\0'; // Null-terminate the substring
	if (substr[start] != 'E')
		ft_check_row(str, substr, 0);
	if (substr[start] != 'F')
		ft_check_row(str, substr, 1);
	if (substr[start] != 'G')
		ft_check_row(str, substr, 2);
	if (substr[start] != '\0')
		ft_check_row(str, substr, 3);

    // Decide whether to continue or stop based on some condition
    // For example, you can stop when the end of the string is reached
    if (str[start + 4] != '\0') {
        // Make a recursive call with an updated starting position
        extract_rows(str, start + 4);
    }
	else
		printf("\n\n");
}



void extract_cols(char *str, size_t start) 
{
    char substr[5]; // To store the extracted 4 digits

    ft_strncpy(substr, str, start, 4);
    substr[4] = '\0'; // Null-terminate the substring

    // Process the extracted substring, e.g., print it
    // printf("Substring: %s\n", substr);
	// ft_check_col(str, substr);
	if (substr[start] != 'E')
		ft_check_row(str, substr, 0);
	if (substr[start] != 'F')
		ft_check_row(str, substr, 1);
	if (substr[start] != 'G')
		ft_check_row(str, substr, 2);
	if (substr[start] != '\0')
		ft_check_row(str, substr, 3);

    // Decide whether to continue or stop based on some condition
    // For example, you can stop when the end of the string is reached
    if (str[start + 4] != '\0') {
        // Make a recursive call with an updated starting position
        extract_cols(str, start + 4);
    }
	else
		printf("\n\n");
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	// int i = 0;
// 	// int j = 4;
//     char *str = "314232413412241314232143AAAA124313422341BBBB31243214CCCC423141324312DDDD132421342314EEEE423141324312FFFF314232413412241314232143GGGG314232413412241314232143";
// 	int start;
// 	// char *first_col_ptr = "AAAA";
// 	// char *second_col_ptr = "BBBB";
// 	// char *third_col_ptr = "CCCC";
//     // char *first_ptr = "DDDD";
//     // char *second_ptr = "EEEE";
//     // char *third_ptr = "FFFF";
//     // char *fourth_ptr = "GGGG";
//     // To store the first 4 characters
// 	// char *first_row = (ft_strnstr(str, first_ptr, ft_strlen(str)));

// 	extract_rows(str, 0);

// 	start = 0;
// 	while (str[start] != 'D')
// 		start++;
// 	start = start + 4;
// 	extract_cols(str, start);
//     // ft_strncpy(substr, str, i, j); // Extract the first 4 characters
// 	// substr[4] = '\0'; // Null-terminate the substring
// 	// int len = ft_strlen(substr);
//     // printf("%s\n", substr);
// 	// printf("%d\n", len);
// 	// const char *first_col = (ft_strnstr(str, first_col_ptr, ft_strlen(str)));
// 	// const char *second_col = (ft_strnstr(str, second_col_ptr, ft_strlen(str)));
// 	// const char *third_col = (ft_strnstr(str, third_col_ptr, ft_strlen(str)));
//     // const char *first_row = (ft_strnstr(str, first_ptr, ft_strlen(str)));
//     // const char *second_row = (ft_strnstr(str, second_ptr, ft_strlen(str)));
//     // const char *third_row = (ft_strnstr(str, third_ptr, ft_strlen(str)));
//     // const char *fourth_row = (ft_strnstr(str, fourth_ptr, ft_strlen(str)));
// 	// int a = ft_strlen(str) - (first_col - str);
// 	// int b = ft_strlen(str) - (second_col - str);
// 	// int c = ft_strlen(str) - (third_col - str);
//     // int w = ft_strlen(str) - (fourth_row - str);
//     // int x = ft_strlen(str) - (third_row - str);
//     // int y = ft_strlen(str) - (second_row - str);
    // int z = ft_strlen(str) - (first_row - str);
	// printf("%ld\n", ft_strlen(str));	
	// printf("%d\n", (z - y));
	// printf("%d\n", (y - x));
	// printf("%d\n", (x - w));
	// printf("%d\n", w);

    // const char *result1 = ft_strnchr(first_row, substr[0], z - y, 0);
    // const char *result2 = ft_strnchr(second_row, substr[1], y - x, 0);
    // const char *result3 = ft_strnchr(third_row, substr[2], x - w, 0);
//     const char *result4 = ft_strnchr(fourth_row, substr[3], w, 0);

//     if (result1 != NULL) {
//         printf("Substring found at position: %ld\n", result1 - str);
//     } else {
//         printf("Substring not found.\n");
//     }
//     if (result2 != NULL) {
//         printf("Substring found at position: %ld\n", result2 - str);
//     } else {
//         printf("Substring not found.\n");
//     }
//     if (result3 != NULL) {
//         printf("Substring found at position: %ld\n", result3 - str);
//     } else {
//         printf("Substring not found.\n");
//     }
//     if (result4 != NULL) {
//         printf("Substring found at position: %ld\n", result4 - str);
//     } else {
//         printf("Substring not found.\n");
//     }
//     return 0;
// }

// char	check_str(char substr, char *str, int i, int j)
// {
// 	i = i + 4;
// 	j = j + 4;
//     ft_strncpy(substr, str, i, j);	
// }
