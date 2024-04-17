// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);

#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
char *ft_strdup(char *src)
{
    int i = 0;

    char *str;
    str = malloc(sizeof(char) * ft_strlen(src) + 1);
    while (src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
int main()
{
    printf("%s",ft_strdup(""));
}
// explained it multiple of time.