// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>
#include <unistd.h>
int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] >= 9 && str[i] <= 13 || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-')
        {
            if (str[i] == '-')
                str[i] = -1;
            i++;
        }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
        return (sign * result);  
}

void ft_putnbr(int nbr)
{
    if (nbr > 9)
    ft_putnbr(nbr / 10);
    char digit = nbr % 10 + '0';
    write (1,&digit,1);
}
int main(int ac, char **av)
{
    int i = 1;
    int n = ft_atoi(av[1]);
    if (ac != 2)
        write(1,"\n", 1);
    else{
        while (i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(n);
            write(1, " = ", 3);
            ft_putnbr(i * n);
            write(1, "\n", 1);
            i++;
        }
        
    }
}
// easy hard coding