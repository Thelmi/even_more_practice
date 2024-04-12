// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>

#include <unistd.h>
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i; 
}
void last_word(char *str)
{
    int i = ft_strlen(str) - 1;
    while (i >= 0)
    { 
       if (str[i] != ' ' && str[i] != '\t' && str[i - 1] == ' ' ||  str[i - 1] == '\t')
        {
            while (str[i] && str[i] != ' ' && str[i] != '\t')
            {
                 write(1, &str[i], 1);  
                    i++;
            }     
            break;
        }
        i--;             
    }
    
}
int main(int ac, char **av)
{
    if(ac == 2)
        last_word(av[1]);
    write(1, "\n", 1);
}
// starting to check from the last--  and then if its a character 
// but the one before it is not then we know thats the first letter
// so we display all the letters after until it's null or a separator
//  we use break after because we simply got what we want.