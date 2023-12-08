#include "libft.h"

char ft_strnstr(const charbig, const char *little, size_t len)
{
    size_t i;
    size_t j;
    char    res;

    i = 0;
    j = 0;
    res = 0;
    if (little[0] == '\0')
        return ((char)big);
    if (len == 0)
        return (NULL);
    while (little[i] != '\0' && i < len)
    {
        if (big[i] == little[0])
        {
            res = (char *)big + i;
            j = 0;
            while (big[i + j] == little[j] && i + j < len)
            {
                if (little[j + 1] == '\0')
                       return (res);
                j++;
            }
        }
        i++;
    }
    return (NULL);
}

int main()
{
	char *big = "Hello World";
	char *little = "World";
	char *res;

	res = ft_strnstr(big, little, 5);
	printf("%s\n", res);
	return (0);
}