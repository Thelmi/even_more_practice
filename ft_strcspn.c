// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j = 0;

    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
           j++;
        }
        i++;
    }
        return (i);
}
int main() 
{

    printf("%zu\n", ft_strcspn("tahahelmy", "q"));
    printf("%zu\n", strcspn("tahahelmy", "q"));
}

// it takes two strings, it checks for every letter in first string, does it occur in 
// the string? if it does it will return the index of that character.