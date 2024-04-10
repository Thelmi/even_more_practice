// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);


int ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    char c;
    int digit_value;

    if (str_base < 2 || str_base > 16)
        return 0;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    
    while(str[i])
    {
        c = str[i];

        if (c >= '0' && c <= '9')   
           digit_value = str[i] - '0';
        else if (c >= 'a' && c <= 'f' )
            digit_value = 10 + c - 'a'; 
        else if (c >= 'A' && c <= 'F' )
            digit_value = 10 + c - 'A'; 
        else 
            return 0;

        if (digit_value >= str_base)
            return 0;
        
        result = result * str_base + digit_value;
        i++;
    }
        return (sign * result);
}
#include <stdio.h>
int main() {
    // Example usage
    const char *str = "1A"; // Hexadecimal representation of 26
    int result = ft_atoi_base(str, 16);
    printf("Result: %d\n", result); // Output should be 26

    return 0;
}

// to understand more about atoi_base read atoi first

// it converts string to ... well depends on the base.. from base 2 to base 16
// not necessary to escape spaces or pluses however make sure of negatives.
// I used same way as in atoi... however important cases to make sure you are handling it is.
//  the base shouldnt be  > 2 or base < 16
/*
    int i = 0;
    int sign = 1;
    int result = 0;

    if (str_base < 2 || str_base > 16)
        return 0;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
*/
// Remember in atoi, to convert character to a number we did, character - '0' that true if it a number 
// for hexadecimal or any base bigger than base 10 it's 10 + character - 'a' if small characters if capital case
// 10 + character - 'A'. also need to make sure that digit value is not bigger than the asked base 

/*
    while(str[i])
    {
        c = str[i];

        if (c >= '0' && c <= '9')   
           digit_value = str[i] - '0';
        else if (c >= 'a' && c <= 'f' )
            digit_value = 10 + c - 'a'; 
        else if (c >= 'A' && c <= 'F' )
            digit_value = 10 + c - 'A'; 
        else 
            return 0;

        if (digit_value >= str_base)
            return 0;
*/
/* comparision between atoi and atoi base formulas

    result = result * 10       + str[i] - '0'
    result = result * str_base + digit_value;
*/