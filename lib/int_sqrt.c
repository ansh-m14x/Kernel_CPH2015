/*
 * Copyright (C) 2013 Davidlohr Bueso <davidlohr.bueso@hp.com>
 *
 *  Based on the shift-and-subtract algorithm for computing integer
 *  square root from Guy L. Steele.
 */

#include <linux/kernel.h>
#include <linux/export.h>

/**
 * int_sqrt - computes the integer square root
 * @x: integer of which to calculate the sqrt
 *
 * Computes: floor(sqrt(x))
 */
unsigned long int_sqrt(unsigned long x)
{
	unsigned long tmp, place, root = 0;

	if (x <= 1)
		return x;

	place = 1UL << (BITS_PER_LONG - 2);

	/* Fast-forward to the first relevant bit */
	while (place > x)
		place >>= 2;

	do {
		tmp = root + place;
		root >>= 1;

		if (x >= tmp) {
			x -= tmp;
			root += place;
		}
		place >>= 2;
	} while (place != 0);

	return root;
}
EXPORT_SYMBOL(int_sqrt);
