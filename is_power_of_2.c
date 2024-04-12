// Assignment name  : is_power_of_2
// Expected files   : is_power_of_2.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that determines if a given number is a power of 2.

// This function returns 1 if the given number is a power of 2, otherwise it returns 0.

// Your function must be declared as follows:

// int	    is_power_of_2(unsigned int n);

#include <stdio.h>
int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    while (n % 2 == 0)
        n /= 2;
    if (n == 1)
        return 1;
    else 
        return 0;
}
/*
     0 is not a power of 2.. but 1 is power of 2... 2 ^ 0.
     if its even and you divide the number by 2 on a loop and nbr was
     always an even number until it became 1 then its power of 2; 
*/ 