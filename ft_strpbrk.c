// Assignment name	: ft_strpbrk
// Expected files	: ft_strpbrk.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strpbrk
// (man strpbrk).

// The function should be prototyped as follows:

// char	*ft_strpbrk(const char *s1, const char *s2);

#include <string.h>
#include <stdio.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
    while (*s1)
    {
        while(*s2)
        {
            if (*s1 == *s2)
                return (char*)s1;
            s2++;
        }
        s1++;
    }
   return (0);
}
// int main()
// {
//     printf("%s\n",ft_strpbrk("taha", "my"));
//     printf("%s\n",strpbrk("taha", "my"));
// }