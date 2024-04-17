// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the
// begin/end of the string.

// If the number of parameters is different from 1, the program will display
// '\n'.

// In the parameters that are going to be tested, there won't be any "additional"
// spaces (meaning that there won't be additionnal spaces at the beginning or at
// the end of the string, and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
// ironic? it Isn't gatherings. love I But people! hate You$
// $>./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "Wingardium Leviosa" | cat -e
// Leviosa Wingardium$
// $> ./rev_wstr | cat -e
// $
// $>

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}
void ft_swap (char *a,char  *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void ft_strev(char *str)
{
    int i = 0;
    int len = ft_strlen(str) - 1;
    while (len > i)
    {
        ft_swap(&str[i], &str[len]);
        i++;
        len--;
    }
}
void rev_wstr(char *str)
{
    int i = 0;
    int j = 0;
    int s = 0;
    ft_strev(str);

    while (str[i])
     {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
        {
            j = i - 1;
            while (j >= s) 
            {
                write(1, &str[j], 1);
                j--;
            }
            if (str[i] != '\0')  
                write(1, " ", 1);
            s = i + 1; 
        }
        i++;    
    }
       if (i > s) 
       {
            j = i - 1;
             while (j >= s) 
            {
                write(1, &str[j], 1);
                j--;
            }
       } 
}
int main(int ac, char **av)
{
    if(ac == 2)
        rev_wstr(av[1]);
    write(1, "\n", 1);
}
// read the question carefully to understand 
/*
    The appraoch I am using is to reverse all the strings using strev function I explained before look at it.
     by reversing it. It makes it easier I just need to find last of the word and then print it backword so 
     basically I used three variables i, j, and s. i = iterates until it find a space. j = last letter and
     then write backward. s is the first letter of each word. Also if it is not the end of the string then,

*/
/*
    void revwstr(char *str)
    {
        int i = 0;
        int j = 0;
        int s = 0;

        ft_strev(str);
        while(str[i])
        {
            if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
                {
                    j = i - 1;
                    if (j >= s)
                        {
                            write(1, &str[i],1)
                            j--;
                        }
                        if (str[i] != '\0')
                            write(1, " ", 1);
                        s = i + 1;
                }
            i++
        }
    }
*/
// now we need to  work with the last word as a separate case.
/*
    if (i > s) 
       {
            j = i - 1;
             while (j >= s) 
            {
                write(1, &str[j], 1);
                j--;
            }
       } 
*/
