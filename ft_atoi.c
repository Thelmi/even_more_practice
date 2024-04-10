

// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

// int	ft_atoi(const char *str);


int ft_atoi(const char *str)
{
    int i = 0; 
    int sign = 1;
    int result = 0;
    while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
             i++;
    if (str[i] == '+' || str[i] == '-')
     {  
        if ( str[i] == '-')
          sign = -1;
        i++;
     }
    while (str[i] || str[i] >= '0' && str[i] <= '9')
        {
         result = result * 10 + str[i] - '0';
         i++;
        }
    return(sign * result);

}
#include <stdio.h>
int main()
{
    printf("%d\n", ft_atoi("123"));
}

// escape all white spaces.
// while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
//     i++;

// escaping pluses and minuses however if it is a negative number then it will let sign flag -1.
// because we will multiply it at the end with the result bec if 1 * num then a positive.
// if multiply -1 then its will be equal a negative number. keep in mind we ignored negatives.
/*
    int i = 0; 
    int sign = 1;
    int result = 0;

    if (str[i] == '+' || str[i] == '-')
     {  
        if ( str[i] == '-')
          sign = -1;
        i++;
     }

     return(sign * result);

*/

/* 
    to convert a character to a number you use c - '0'; so we want to make a while loop and a formula which will
    let us to convert all characters. so we loop in a string from left to right... so we should after converting
    first character to a number to multiply it by ten to go to the next digit then we add plus the second digit. 
 */
//  result = result * 10 + str[i] - '0';

/*
    while (str[i] || str[i] >= '0' && str[i] <= '9')
        {
         result = result * 10 + str[i] - '0';
         i++;
        }
*/

