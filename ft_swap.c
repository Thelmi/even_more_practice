// Assignment name  : ft_swap
// Expected files   : ft_swap.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that swaps the contents of two integers the adresses of which
// are passed as parameters.

// Your function must be declared as follows:

// void	ft_swap(int *a, int *b);

#include <stdio.h>
void ft_swap(int *a, int *b)
{
   int tmp = *a;
    *a = *b;
    *b = tmp;
}
// it simply swaps two values using a help of tmp. 