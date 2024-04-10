// Assignment name  : fprime
// Expected files   : fprime.c
// Allowed functions: printf, atoi
// --------------------------------------------------------------------------------

// Write a program that takes a positive int and displays its prime factors on the
// standard output, followed by a newline.

// Factors must be displayed in ascending order and separated by '*', so that
// the expression in the output gives the right result.

// If the number of parameters is not 1, simply display a newline.

// The input, when there is one, will be valid.

// Examples:

// $> ./fprime 225225 | cat -e
// 3*3*5*5*7*11*13$
// $> ./fprime 8333325 | cat -e
// 3*3*5*5*7*11*13*37$
// $> ./fprime 9539 | cat -e
// 9539$
// $> ./fprime 804577 | cat -e
// 804577$
// $> ./fprime 42 | cat -e
// 2*3*7$
// $> ./fprime 1 | cat -e
// 1$
// $> ./fprime | cat -e
// $
// $> ./fprime 42 21 | cat -e
// $

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int ft_isprime(int nbr)
{
    int i = 2;
    if (nbr == 0 || nbr == 1)
        return 0;
    while (i * i <= nbr)
    {
        if (nbr % i == 0)
            return 0;
        i++;
    }
        return 1;
}
void prime_factors(int num)
{
    int i = 2;
    int print = 0;
    if (num == 1)
    {
        printf("%d", 1);
        return;
    }
        while(i <= num)
        {
            if (ft_isprime(i) && num % i == 0)
            {
                if (print)
                    printf("%c",'*');
                printf("%d", i);
                print = 1;
                num /= i;
            }
            if (num % i != 0)
                i++;
        }
}
int main(int ac, char **av)
{
    if (ac == 2)
        prime_factors(atoi(av[1]));
    printf("%c", '\n');
}

// if the number is not prime dont change anything in case its 1 print 1 
// so for printing one. manually using an if statement
/*
        if (num == 1)
    {
        printf("%d", 1);
        return;
    }
*/
// after that we need to check starting from number 2 // int i = 2
 
// We need to make sure if (i) is smaller or equal to (num), also if (i) is a prime number or not 
// also if (num % i == 0) or not 

/*
    if(i <= num){
        while(is_prime(i) && num % i == 0)
    }
*/
// We need to create is prime function first if the number is 0 || 1 then its not a prime (0); 
// we start checking from 2. (i = 2); also we need to check all numbers until square root of 
// that number. algebra basics (i * i <= num); anyhow if the num % i == 0; then its not prime (0)
// if after all that it didn't return 0; then its a prime (1);

/*
    int isprime(int num)
    {
        if (num == 0 || num == 1)
            return 0;
        int i = 2;
        while (i * i <= num)
            {
                if (num % i == 0)
                    return 0;
                i++;
            }
            return 1;
    }
*/

// after we have our isprime  function. we need to make sure when to print *;
// so we basically set a flag as 0 and when it prints a number then it set to 1;
/*
    if (num == 1)
        print("%d", 1);
    int i = 2;
    int print = 0;

    if (isprime(num) && num % i == 0)
    {
        if (print)
            printf("%c", '*')
        print(%d, i);
        print = 1;
        num /= i;          // to do a factiorial(num) then we need to decrement num / the number already printed 
    }
*/ 
// in case (num % i != 0) check the next num;
/*
    if (num == 1)
        print("%d", 1);
    
    int i = 2;
    int print = 0;

    while (i <= num)
    {
        if (isprime(i) && num % i == 0)
        {
            if (print)
                print("%c", '*');
            print("%d", i);
            print = 1;
            num /= i;
        }
        if (num % i != 0)
            i++;
    }
*/
