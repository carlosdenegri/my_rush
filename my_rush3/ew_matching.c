#include <stdio.h>
#include <string.h>
#include <ctype.h>

void groupCharacters(char *input) {
    int length = strlen(input);
    char result[length + 1]; // +1 for the null terminator
    int resultIndex = 0;
    char lastAlpha = '\0';
	int i = 0;

while(input[i])
{
        char currentChar = input[i];

        if (isalpha(currentChar))
		{
            lastAlpha = currentChar;
			// i = i + 8;
            if (input[i + 8] != lastAlpha)
			{
                input[i + 8] = currentChar;
                result[resultIndex++] = lastAlpha;
                result[resultIndex++] = lastAlpha;
                result[resultIndex++] = lastAlpha;
                result[resultIndex++] = lastAlpha;
            }
			else
			{
				i = i + 4;
			}
        } else {
            result[resultIndex++] = currentChar;
        }
		i++;
    }

    result[resultIndex] = '\0'; // Null-terminate the result string
    strcpy(input, result); // Copy the result back to the input string
}

int main() {
    char str1[] = "4213AAAA3124BBBB1432CCCC1342DDDD2341DDDD4312EEEE2143FFFF1234GGGG3421HHHH";
    char str2[] = "4213AAAA3124AAAA2134BBBB1432CCCC4123CCCC1342DDDD2341DDDD4312EEEE2143FFFF1234GGGG3421HHHH";

    groupCharacters(str1);
    groupCharacters(str2);

    printf("Result 1: %s\n", str1);
    printf("Result 2: %s\n", str2);

    return 0;
}
				// j = 0;
				// while(j < length)
				// {
				// 	if (isalpha(currentChar))
				// 		if (currentChar == lastAlpha)
				// 			j++;
				// 		else
				// 		{
				// 			currentChar = lastAlpha;
				// 			j = length
				// 		}
				// }