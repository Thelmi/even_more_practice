// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e
// 1$
// $> ./pgcd | cat -e
// $

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void pgcd(int n1, int n2)
{
    while (n1 != n2)
    {
        if (n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    printf("%d", n1);
    
}
int main(int ac, char **av)
{
    if (ac == 3 && atoi(av[1]) >= 0 && atoi(av[2]) >= 0)
            pgcd(atoi(av[1]), atoi(av[2]));
    if (atoi(av[1]) < 0 || atoi(av[2]) < 0)
            return 0;
    printf("%c", '\n');
}