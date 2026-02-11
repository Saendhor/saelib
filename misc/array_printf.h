#ifndef ARRAY_PRINTF_H
#define ARRAY_PRINTF_H

#include <stdio.h>

int array_printf(double input[], int size) {
	for (int i = 0; i < size; i++) {
		printf("[MISC] Item in slot n.%d is %lf\n", i, input[i]);
	}
	return 0;
}
#endif
