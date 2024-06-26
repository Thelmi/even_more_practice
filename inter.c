// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

// if there is no doubles, and if its in the other array display it 
#include <unistd.h>
int checker(char c, char *str2)
{
    int i = 0;
        while (str2[i])
        {
            if (str2[i] == c)
                return 1;
         i++;
        }
    return 0; 
}   

int doublechecker(char *str1, int index)
{
    int i = 0;
    while (i < index)
    {
        if (str1[i] == str1[index])
            return 0;
        i++;
    }
    return 1; 
}

void inter (char *s1, char *s2)
{
    int i = 0;
    while(s1[i])
    {
        if(doublechecker(s1, i) && checker(s1[i], s2))
            write(1, &s1[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
        inter(av[1], av[2]);
    write(1,"\n", 1);
}
/*
 two checks are in need to meet the criteria, 
 first it needs to not be a double in s1 

 if it is double then display it once
 second it should occur on both s1 and s2
*/
// for the double checker we are going to compare the character
//  we are on if it occured on the same string before or not.  

/*
int double_checker(char *str, int index)
{
    int i = 0;
    while(i < index)
    {
        if (str[i] == str[index])
            return 0;
        i++;
    }
    return 1;
}

int i = 0;

while (s1[i])
{
    if (double_cheker(s1, i))
}
*/
// then we just do a normal checker which checks if s1[i] occurs in s2

/*

int checker(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}
int double_checker(char *str, int index)
{
    int i = 0;
    while(i < index)
    {
        if (str[i] == str[index])
            return 0;
        i++;
    }
    return 1;
}

    int i = 0;

    while (s1[i])
    {
        if (double_checker(s1, i) && checker(s1[i], s2))
            write(1, &s1[i], 1);
        i++;
    }
*/