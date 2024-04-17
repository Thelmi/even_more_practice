// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>
#include <stdio.h>

void *t_strcat(char *s1,char *s2)
{
    int i = 0;
    int j = 0;
    while (s1[i])
        i++;
    while (s2[j])
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}

int double_cheaker(char *str,int index)
{
    int i = 0;
    
    while(i < index)
    {
        if (str[i] == str[index])
            return(0);
        i++;
    }
         return (1);
}


void t_union(char *s1, char *s2)
{
    int i = 0;

    t_strcat(s1, s2);

    while (s1[i])
    {
        if (double_cheaker(s1, i))
            write(1, &s1[i],1);
        i++;
    }
}

int main(int ac , char**av)
{
    if (ac == 3)
        t_union(av[1],av[2]);
    write(1, "\n", 1);
}
// easy approach is to strcat and then check for double... read inter you understand more..