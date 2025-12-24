#ifndef ARRAY_PRINTF_H
#define ARRAY_PRINTF_H

#include <stdio.h>

int array_printf_i (int* input, int size) {
	for (int i = 0; i < size; i++) {
		printf("[MISC] Item in slot n.%d is %d\n", i, input[i]);
	}
	return 0;
}
#endif
