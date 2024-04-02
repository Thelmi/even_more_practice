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