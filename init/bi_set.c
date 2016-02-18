#include "bi_intl.h"

void bi_set(bigint *dest, bigint src){
	/*
	 * Set the value of dest to the value in src.
	 */
	dest->len = src.len;
	dest->val = realloc(dest->val, (dest->len)*sizeof(uint32_t));
	dest->val = memcpy(dest->val, src.val, dest->len*sizeof(uint32_t));
	dest->sgn = src.sgn;
}

