// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// char* removeFrontChars(const char* input, size_t charsToRemove) {
//     size_t inputLength = strlen(input);

//     // Ensure charsToRemove is not greater than the input string length
//     if (charsToRemove >= inputLength) {
//         return strdup(""); // Return an empty string
//     }

//     // Calculate the length of the new string after removal
//     size_t newLength = inputLength - charsToRemove;

//     // Allocate memory for the new string
//     char* result = (char*)malloc(newLength + 1);

//     if (result == NULL) {
//         return NULL; // Memory allocation failed
//     }

//     // Copy the desired substring into the new string
//     strncpy(result, input + charsToRemove, newLength);

//     // Null-terminate the new string
//     result[newLength] = '\0';

//     return result;
// }

// int main() {
//     const char* originalString = "Hello, World!";
//     size_t charsToRemove = 6;

//     char* modifiedString = removeFrontChars(originalString, charsToRemove);

//     if (modifiedString) {
//         printf("Original: %s\n", originalString);
//         printf("Modified: %s\n", modifiedString);
//         free(modifiedString); // Don't forget to free the dynamically allocated memory
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }

//ERASE CHAR WITHIN THE STR

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     // Allocate a string with extra space
//     char *originalString = (char *)calloc(20, sizeof(char));

//     if (originalString == NULL) {
//         printf("Memory allocation failed.\n");
//         return 1;
//     }

//     // Initialize the string
//     const char *initialContent = "This is a test string.";

//     // Copy the initial content, ensuring it doesn't exceed the allocated space
//     size_t initialLength = strlen(initialContent);
//     if (initialLength >= 20) {
//         initialLength = 19; // Limit the length to fit in the allocated space
//     }
//     strncpy(originalString, initialContent, initialLength);
//     originalString[initialLength] = '\0';

//     // Current position and remaining length
//     char *currentPosition = originalString;
//     size_t remainingLength = strlen(originalString);

//     // Remove characters from the beginning in chunks of 4
//     while (remainingLength >= 4) {
//         // Move the current position forward by 4 characters
//         currentPosition += 4;

//         // Update the remaining length
//         remainingLength -= 4;

//         // Copy the remaining part back to the original position
//         memmove(originalString, currentPosition, remainingLength + 1);
//     }

//     printf("Modified String: %s\n", originalString);

//     // Free the memory when you're done
//     free(originalString);

//     return 0;
// }

//USE PART OF THE STR AS A SUBSTR
#include <stddef.h>
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

char *ft_strncpy(char *dest, const char *src, size_t n) {
    char *original_dest = dest; // Store the original destination pointer

    // Copy up to n characters from src to dest
    while (n > 0 && *src != '\0') {
        *dest++ = *src++;
        n--;
    }

    // Fill the remaining space in dest with null characters
    while (n > 0) {
        *dest++ = '\0';
        n--;
    }

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


int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "31243214AAAA423141324312BBBB124313422341CCCC314232413412241314232143DDDD342114322431EEEE132421342314FFFF124313422341GGGG41234213";
    char *first_ptr = "DDDD";
    char *second_ptr = "EEEE";
    char *third_ptr = "FFFF";
    char *fourth_ptr = "GGGG";
    char substr[4] = "1423"; // To store the first 4 characters

    // ft_strncpy(substr, str, 4); // Extract the first 4 characters
    substr[4] = '\0'; // Null-terminate the substring
    printf("%s\n", substr);
    const char *first_row = (ft_strnstr(str, first_ptr, ft_strlen(str)));
    const char *second_row = (ft_strnstr(str, second_ptr, ft_strlen(str)));
    const char *third_row = (ft_strnstr(str, third_ptr, ft_strlen(str)));
    const char *fourth_row = (ft_strnstr(str, fourth_ptr, ft_strlen(str)));
    int w = ft_strlen(str) - (fourth_row - str);
    int x = ft_strlen(str) - (third_row - str);
    int y = ft_strlen(str) - (second_row - str);
    int z = ft_strlen(str) - (first_row - str);
	printf("%ld\n", ft_strlen(str));	
	printf("%d\n", (z - y));
	printf("%d\n", (y - x));
	printf("%d\n", (x - w));
	printf("%d\n", w);
    const char *result1 = ft_strnchr(first_row, substr[0], z - y, 3);
    const char *result2 = ft_strnchr(second_row, substr[1], y - x, 3);
    const char *result3 = ft_strnchr(third_row, substr[2], x - w, 3);
    const char *result4 = ft_strnchr(fourth_row, substr[3], w, 3);

    if (result1 != NULL) {
        printf("Substring found at position: %ld\n", result1 - str);
    } else {
        printf("Substring not found.\n");
    }
    if (result2 != NULL) {
        printf("Substring found at position: %ld\n", result2 - str);
    } else {
        printf("Substring not found.\n");
    }
    if (result3 != NULL) {
        printf("Substring found at position: %ld\n", result3 - str);
    } else {
        printf("Substring not found.\n");
    }
    if (result4 != NULL) {
        printf("Substring found at position: %ld\n", result4 - str);
    } else {
        printf("Substring not found.\n");
    }
    return 0;
}

// #include <stdio.h>
// #include <string.h>
// #include <limits.h>
// #include <stdint.h>

// int main() {
//     const char *bigstr = "car an brow law own sail";
//     const char *little = "carlos";
//     size_t little_len = strlen(little);
//     size_t bigstr_len = strlen(bigstr);

//     printf("Occurrences of 'carlos' in 'car an brow law own sail':\n");

//     for (size_t i = 0; i < bigstr_len - little_len + 1; i++) {
//         if (strncmp(bigstr + i, little, little_len) == 0) {
//             // Check if "carlos" appears after every 4 spaces
//             size_t space_count = 0;
//             size_t j = i - 1; // Start before the matched string
//             while (j != SIZE_MAX && bigstr[j] == ' ') {
//                 space_count++;
//                 j--;
//             }
//             if (space_count % 4 == 0) {
//                 printf("Found 'carlos' at position %lu: %s\n", i, bigstr + i);
//             }
//         }
//     }

//     return 0;
// }


