char strA[] = "1200,4123,4213"
char strB[] = "1300,4231,4132,4312"
char strC[] = "1400,4321"
char strD[] = "2100,3124,3214"
char strE[] = "2200,3142,3241,3412,2413,1423,2143"
char strF[] = "2300,3421,1432,2431"
char strG[] = "3100,1324,2134,2314"
char strH[] = "3200,1243,1342,2341"
char strI[] = "4100,1234"


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