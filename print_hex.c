#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *decToHex(unsigned input)
{
    char *output = malloc(sizeof(unsigned) * 2 + 3);
    strcpy(output, "0x00000000");

    static char HEX[] = "0123456789ABCDEF";
    int index = 9;
    while (input > 0)
	{
        output[index--] = HEX[(input & 0xF)];
        input >>= 4;
    }
    return output;
}

void print_hex(unsigned int input)
{
	char hex[] = "0123456789ABCDEF";

	if (input > 0)
		print_hex(input >> 4);
	if (input != 0)
		write(STDOUT_FILENO, &hex[(input & 0xF)], sizeof(char));
}

void print_bit(int input)
{
	unsigned char byte = 1;
	
	byte = byte << 7;
	while (byte != 0)
	{
		if (input & byte)
			write(STDOUT_FILENO, "1", sizeof(char));
		else
			write(STDOUT_FILENO, "0", sizeof(char));
		byte = byte >> 1;
	}		
}

int	main(int argc, char *argv[])
{
	// printf("%s", decToHex('a'));
	// print_bit('a');
	argc++;
	print_hex(*argv[1]);
	return (0);
}