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
    char *nstr = malloc(sizeof(char) * (ft_strlen(str) - len) + 1);
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
#include <stdio.h>
int main()
{
    int i = 0;
    char *str = "Hello world!";
    char **result = ft_split(str);
    while (result[i])
    {
        printf("%s\n",result[i]);
        i++;
    }
    printf("Word count = %d \n", word_count(str));
}
// #include <stdio.h>

// int main() {
//     char str[] = "maaz ";

//     // Calling word_count function with a string literal
//     int count = word_count("Hello world!");

//     printf("Number of words: %d\n", count);

//     return 0;
// }
// "space space taha space space maaz space 7o"
// "taha space 7o space maaz space"
// "taha space 7o space space maazz"
