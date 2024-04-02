// Write a program that takes a single string in snake_case format
// and converts it into a string in lowerCamelCase format.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// Examples:
// $>./snake_to_camel "here_is_a_snake_case_word"
// hereIsASnakeCaseWord
// $>./snake_to_camel "hello_world" | cat -e
// helloWorld$
// $>./snake_to_camel | cat -e
// $

#include <unistd.h>

void trim_delimiter(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == '_')
            i++;
        write(1, &str[i], 1);
        i++;
    }

}
void snake_to_camel(char *str)
{
    int i = 0;
    while (str[i])
    {
        if(str[i] == '_')
        {
            i++;
            str[i] -= 32;
        }
        i++;
    }
    trim_delimiter(str);
}
int main(int ac , char **av)
{
    if (ac == 2)
        snake_to_camel(av[1]);
    write(1,"\n",1);
}