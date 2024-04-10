// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);  
}

char *ft_strdup(char *str)
{
    int i = 0;
    char *nstr = malloc(sizeof(char) * ft_strlen(str) + 1);
    if (!nstr)
        return NULL;
    while (str[i])
    {
        nstr[i] = str[i];
        i++;
    }
        nstr[i] = '\0';
        return (nstr);
}

int digitcount(int nbr)
{
    int count = 0;
    if (nbr < 0)
        {
            nbr *= -1;
            count++;
        }
    while (nbr > 0)
        {
            nbr /= 10;
            count++;
        }
            return (count);
}

char  *ft_itoa(int nbr)
{
    int i = 0;
    if (nbr == -2147483648)
        return (ft_strdup("-2147483648"));
    if (nbr == 0)
        return (ft_strdup("0"));

    int count = digitcount(nbr);

    char *str = malloc(sizeof(char) * (count + 1));
    if (!str)
        return NULL;
    str[count] = '\0';
    if (nbr < 0)
    {
        nbr *= -1;
        str[0] = '-';
    }

    while (count-- > 0 && nbr > 0)
	{
		str[count] = (nbr % 10) + '0';
		nbr /= 10;
	}
    return (str);
}
// int main()
// {
//     printf("%s\n", ft_itoa(-55));
// }

// look at Atoi first because its easier and will help you understand itoa.
/*
    Need to malloc for the string so we need to know the number of digits.
    we need to figure out the size of the malloc we need. we need to count the digits of the number put in mind 
    that if the number is negative should add one as well.
    
    int digitcount (int nbr)
    {
        int count = 0;

        if (nbr < 0)
        {
            nbr *= 1;
            count++
        }
        while (nbr > 0)
        {
            nbr /= 10;
            count++;
        }
        return count;
    }
*/
/*
Now we need to make sure for certain cases like int min: -2147483648 because if we remove the - then it will 
be higher than what int can take (int max = 2147483647)... also another case 0 would be a case as well.
I didnt put in my mind. I want to just return the duplicate the number string manually if any of both cases
*/
