#ifndef SWAP_H
#define SWAP_H

int swap (double* elem1, double* elem2) {
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
	return 0;
}

#endif