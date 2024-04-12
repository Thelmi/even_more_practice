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
   int i = 0;
   int j;

   while (s1[i])
   {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return (char *)s1 + i;
            j++;
        }
        i++;
   }
   return (NULL);
}
int main()
{
    printf("%s\n",ft_strpbrk("taha", "hah"));
    printf("%s\n",strpbrk("taha", "hah"));
}
// it checks each letter in s1 if it exist in s2. if it does return a pointer on that character.