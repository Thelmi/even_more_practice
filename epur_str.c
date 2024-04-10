// Assignment name  : epur_str
// Expected files   : epur_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string, and displays this string with exactly one
// space between words, with no spaces or tabs either at the beginning or the end,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// If the number of arguments is not 1, or if there are no words to display, the
// program displays \n.

// Example:

// $> ./epur_str "See? It's easy to print the same thing" | cat -e
// See? It's easy to print the same thing$
// $> ./epur_str " this        time it      will     be    more complex  . " | cat -e
// this time it will be more complex .$
// $> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// $
// $> ./epur_str "" | cat -e
// $
// $>

//
#include <unistd.h>

// void epur_str(char *str)
// {
//     int i = 0;
//     while (str[i] == ' ' || str[i] == '\t') 
//         i++;
//     while(str[i])
//     {
//         if (str[i] != ' ' && str[i] != '\t')
//                 write(1, &str[i], 1);
//         else
//         {
//             if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i + 1] != '\0')
//                 write(1," ", 1);
//         }   
//         i++;
//     }
// }

void epur_str(char *str)
{
    int i = 0;
    int flag = 0;

while (str[i])
{
    if (str[i] == ' ' || str[i] == '\t')
            flag = 1;
    if ((str[i] != ' ' && str[i] != '\t'))
    {
        if(flag)
            write(1, " ", 1);
        flag = 0;
        write(1, &str[i], 1);
    }
    i++;
}
}
int main (int ac, char ** av)
{
    if(ac == 2)
      epur_str(av[1]);
    write(1, "\n", 1);
}
// to implement this a flag is used and initialized as false any time encounter a space, its becoming true 
// then when it encounter anything else it writes " " and and turn flag re initialize it to false again 
// after that it writes the letter and all that on a loop.