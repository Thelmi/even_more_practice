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
int main()
{
    printf("%s\n", ft_itoa(-55));
}
    //  ft_itoa(nbr / 10);
    // str[count] = (nbr % 10) + '0';