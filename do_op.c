// Assignment name  : do_op
// Expected files   : *.c, *.h
// Allowed functions: atoi, printf, write
// --------------------------------------------------------------------------------

// Write a program that takes three strings:
// - The first and the third one are representations of base-10 signed integers
//   that fit in an int.
// - The second one is an arithmetic operator chosen from: + - * / %

// The program must display the result of the requested arithmetic operation,
// followed by a newline. If the number of parameters is not 3, the program
// just displays a newline.

// You can assume the string have no mistakes or extraneous characters. Negative
// numbers, in input or output, will have one and only one leading '-'. The
// result of the operation fits in an int.

// Examples:

// $> ./do_op "123" "*" 456 | cat -e
// 56088$
// $> ./do_op "9828" "/" 234 | cat -e
// 42$
// $> ./do_op "1" "+" "-43" | cat -e
// -42$
// $> ./do_op | cat -e
// $
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    do_op(char *exp1, char op, char *exp2)
{

    if (op == '+')
        printf ("%d" , atoi(exp1) + atoi(exp2));
    else if (op == '-')
        printf ("%d", atoi(exp1) - atoi(exp2));
    else if (op == '*')
        printf ("%d", atoi(exp1) * atoi(exp2));
    else if (op == '/')
        printf ("%d", atoi(exp1) / atoi(exp2));
    else if (op == '%')
        printf ("%d", atoi(exp1) % atoi(exp2));
}
int main(int ac, char **av)
{
    if(ac == 4)
        do_op(av[1], av[2][0], av[3]);
    write(1, "\n", 1);
}
// A simple if statement... depends on operation stated on third arg. 
// The expression between 2 arg and 4th will differ