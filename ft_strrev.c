// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
char *ft_strrev(char *str)
{
    int i = 0;
    int len = ft_strlen(str) - 1;

    while(i < len)
    {
        swap(&str[i], &str[len]);
        i++;
        len--;
    }
    return(str);
}

#include <stdio.h>
int main()
{
    char str[] = "taha";
    printf("%s\n",ft_strrev(str));
}