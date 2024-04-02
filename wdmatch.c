// Assignment name  : wdmatch
// Expected files   : wdmatch.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and checks whether it's possible to
// write the first string with characters from the second string, while respecting
// the order in which these characters appear in the second string.

// If it's possible, the program displays the string, followed by a \n, otherwise
// it simply displays a \n.

// If the number of arguments is not 2, the program displays a \n.

// Examples:

// $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
// faya$
// $>./wdmatch "faya" "fgvvfdxcacpolhyhbred" | cat -e
// $
// $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
// quarante deux$
// $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
// $
// $>./wdmatch | cat -e
// $

#include <unistd.h>
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}


void wdmatch(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    while(s2[j])
    {
        if(s2[j] == s1[i])
            i++;
        j++;
    }
    if(!s1[i])
        ft_putstr(s1);  
}

int main(int ac, char**av)
{
    if (ac == 3)
        wdmatch(av[1], av[2]);
    write(1,"\n",1);
}