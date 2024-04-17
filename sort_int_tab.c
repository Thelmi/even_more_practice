// Assignment name  : sort_int_tab
// Expected files   : sort_int_tab.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write the following function:

// void sort_int_tab(int *tab, unsigned int size);

// It must sort (in-place) the 'tab' int array, that contains exactly 'size'
// members, in ascending order.

// Doubles must be preserved.

// Input is always coherent.

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    int temp;
    
    while (i < (size - 1))
    {
        if (tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0;
        }
         else 
                i++;
    }
    
}
// (size - 1) because i starts from 0 (indexed)... I will iterate until I find a vlue which is bigger than the one after it. then just swap it and every time 
// and after that just restart i and check from the beginning 