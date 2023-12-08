#include <stdio.h>

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
    size_t i;
    size_t j;
    char    *res;

    i = 0;
    j = 0;
    res = 0;
    if (s2[0] == '\0')
        return ((char *)s1);
    if (n == 0)
        return (NULL);
    while (s1[i] != '\0' && i < n)
    {
        if (s1[i] == s2[0])
        {
            res = (char *)s1 + i;
            j = 0;
            while (s1[i + j] == s2[j] && i + j < n)
            {
                if (s2[j + 1] == '\0')
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
	char *s1 = "Hello World";
	char *s2 = "World";
	char *res = ft_strnstr(s1, s2, 5);
	printf("%s\n", res);
	return (0);
}