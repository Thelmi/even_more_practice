// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void	print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"
#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		if (octet & 1 << i)
			bit = '1';
		else 
			bit = '0';
		write(1, &bit, 1);
	}
}
int main()
{
    unsigned char value = 2;
    print_bits(value);
    return 0;
}
