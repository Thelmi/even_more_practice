// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.

// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.

// Your function must be declared as follows:

// char    **ft_split(char *str);

#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int ft_strncpy(char *s1, char*s2, int len)
{
    int i = 0;
    while (s2[i] && i < len)
    {
       s1[i] = s2[i];
       i++;
    }
    s1[i] = '\0';
    return (i);
}

char *ft_substr(char *str, unsigned int start, unsigned int len)
{
    if (start + len > ft_strlen(str))
    {
        char *nstr = malloc(sizeof(char) * (ft_strlen(str) - start) + 1);
        if (!nstr)
            return NULL;
        ft_strncpy(str, str + start, ft_strlen(str) - start);
        return (nstr);
    }
    else
    {
    char *nstr = malloc(sizeof(char) * len + 1);
    if (!nstr)
        return NULL;
     ft_strncpy(nstr, str + start, len);
     return (nstr);
    }
}

int word_count(char *str)
{
    int i = 0;
    int word = 0;

    while (str[i])
    {
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        {
            if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\n' || str[i + 1] == '\0')
                word++;
            i++;
        }
            if (str[i] == '\0')
                break;
            i++;
    }
    return (word);
}
char **getwords(char **arr, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        j = i;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        if (j < i)
            arr[k++] = ft_substr(str, j , i - j);
    }
    arr[k] = NULL;
    return (arr);
}

char **ft_split(char *str)
{
    int str_count = word_count(str);
    char **arr_of_str = malloc(sizeof(char *) * str_count + 1);
    if (!arr_of_str)
        return NULL;   
    return (getwords(arr_of_str, str));
}
//tests
#include <stdio.h>
int main()
{
    int i = 0;
    char *str = "H";
    char **result = ft_split(str);
    while (result[i])
    {
        printf("%s\n",result[i]);
        i++;
    }
    printf("Word count = %d \n", word_count(str));
}
#include <stdio.h>

// int main() {
//     char str[] = "maaz ";

//     int count = word_count("Hello world!");

//     printf("Number of words: %d\n", count);

//     return 0;
// }
// ************************************************************

/* 
    split return 2d array so we need to put two things in our mind.
    mallocing for the big array and mallocing for each array 
    imagine it like this [[apple], [orange], [banana] , [mango]]

    so basically we want to malloc for the outer array and then the arrays 
    inside.
    To do so we need to know how many words in the string you will extract
    and  how long is each word.
*/

/*  
    to get how many words... there many ways... try your own.
    The one I thought about has an easy aproach 
    so basically, it will iterate until it reaches the first letter and then it
    will iterate again until it reaches the last letter of the word...
    keep in mind last letter always has a separator after it or NULL if it's the last
    thig in the string 

    We need to make sure that when it reaches null 
    it doesn't count any thing so we break when we counter null
*/
/*
    int words_count(char *str)
    {
        int i = 0;
        int word = 0;

        while (str[i])
        {
            while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            {
                if (str[i + 1] == ' ' || str[i + 1] != '\t' || str[i + 1] != '\n' || str[i + 1] != '\0')
                    word++;
                i++;
            }
            if (str[i] == '\0')
                return (NULL);
            i++;
        }
    }
*/
// now we can malloc the outer array...
/*
    int str_count = ft_words_count(str);
    char **arr_of_str = malloc(sizeof(char *) * str_count + 1);
    if(!arr_of_str)
        return NULL; 
*/ 

/*
    now what is left is mallocing for each string to do so I used a helper function which is called 
    substring. it basically duplicate a string... but you can decide from what to what you want
    to dupilacte (start and end); 
    now what left is to find the start and end of each word. 
*/
/*
    to get the start and end, I simply used two iteration variables, i and j, i iterate through all
    separators until it reaches a letter. When it does, the value get assigned to j 
    then i just iterate through the letters and stops on the last letter before sperator it duplicate 
    the word then its in a loop until it reaches null.
*/

/*
    char **arr(char **arr , char *str)
    {
        int i = 0;
        int j = 0;

        while(str[i])
        {
            while(str[i] == ' ' && str[i] == '\t' && str[i] == '\n')
                    i++;
            i = j;
            while(str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
                    i++;
            if (j < i)      //a word exist
                arr[k++] = ft_substr(str,i, i -j);
        }
        arr[k] = NULL;
        return (arr)
    }
*/
// nice but how to do ft_substr. I used ft_strncpy to copy the part I want to the new duplicated string.

/*
    char* ft_strncpy(char* dst, char *src , int len)
    {
        int i = 0;
        while(str[i] && i < len)
        {
            dst[i] = src[i]
            i++;
        }
        str[i] = '\0';
        return (str);
    }
*/

/*
 char *ft_substr(char *str, unsigned int start, unsigned len)
 {
    if (start + len < ft_strlen(str))
    {
        char *nstr = malloc(sizeof(char) * (ft_strlen(str) - start) + 1);
        if (!nstr)
            return NULL;
        ft_strncpy(str, str + start, ft_strlen(str) - start);
        return (nstr);
    }
    else 
    {
        char *nstr = malloc(sizeof(char) * len + 1)
        if (!nstr)
            return NULL;
        ft_strncpy(nstr, str + start, len)
    }
    
 }
*/



