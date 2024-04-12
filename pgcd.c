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

// if n1 > n2           else
// n1 = n1 - n2         n2 = n2 - n1

// n1 = 42   n2 = 10    10 = 10 - 2
// n1 = 42 - 10 = 32     8 = 8 - 2
// n1 = 32 - 10 = 22     6 = 6 -2 
// n1 = 22 - 10 = 12      4 = 4 -2 
// n1 = 12 - 10 = 2                   both now are 2 here where the condition take place (n1 != n2)

