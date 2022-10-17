#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array
 * @buff_ind: Buffer index
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
