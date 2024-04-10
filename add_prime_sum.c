//  Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;

    while(str[i])
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
        return (result);
}

void t_putnbr(int n)
{
    if(n >= 10)
        t_putnbr(n / 10);
    char digit = n % 10 + '0';
        write(1, &digit, 1);
}

int	isprime(int num)
{
	int	i = 2;

	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void add_prime_sum(int num)
{
    int sum = 0;
    while (0 < num)
    {
        if (isprime(num))
            sum += num;
        num--;
    }
    t_putnbr(sum);
}

int main(int ac, char **av)
{
    if (ac != 2 || ft_atoi(av[1]) <= 0) {
         t_putnbr(0);
    } else {
         add_prime_sum(ft_atoi(av[1]));
    }
    write(1, "\n", 1);
    return 0;
}

// If the number num is less than or equal to 1, it is not considered prime.
//  Thus, the function returns 0 in such cases.
// int	i = 2;
// 	if (num <= 1)
// 		return (0);
// Next, the function loops through all numbers from 2 to the square root of num. 
// It does this to check for divisibility by smaller numbers.
//  If num is divisible by any number in this range, it means num is not prime.
// while (i * i <= num)     // i <= num square root of num 
// 	{
// 		if (num % i == 0)
// 			return (0);
// 		i++;
// 	}

// displays the sum
// of all prime numbers inferior or equal
// void add_prime_sum(int num)
// {
//     int sum = 0;
//     while (0 < num)
//     {
//         if (isprime(num))
//             sum += num;
//         num--;
//     }
//     t_putnbr(sum);
// }

// put in mind usage ( + '0') is from integer to string (- '0') is to convert from string to integer