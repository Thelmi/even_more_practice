// Assignment name  : max
// Expected files   : max.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// int		max(int* tab, unsigned int len);

// The first parameter is an array of int, the second is the number of elements in
// the array.

// The function returns the largest number found in the array.

// If the array is empty, the function returns 0.

#include <stdio.h>
int max (int* tab, unsigned int len)
{
    unsigned int i = 0;
    unsigned int result;

    if (len == 0)
        return 0;

    result = tab[i];
    while (i < len)
    {
        if(result < tab[i])
            result = tab[i];
        i++;
    }
    return (result);
}
int main()
{
    int arr[5] = {0 ,5, 2, 8, 7};
    int len = 5;
    printf("%d", max(arr, len));
}