// Assignment name  : ft_putstr
// Expected files   : ft_putstr.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that displays a string on the standard output.

// The pointer passed to the function contains the address of the string's first
// character.

// Your function must be declared as follows:

// void	ft_putstr(char *str);

#include <unistd.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i++]);
         return i;  
}
void ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}