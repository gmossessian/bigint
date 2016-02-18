#include "bi_intl.h"

void bi_init_len(bigint *r, size_t len){
/*
 * all other initialization functions should refer to this one
 * initalizes a length=len, 0-value bigint.
 */
	r->val = calloc(len, sizeof(uint32_t));
	r->len = len;
	r->sgn=BI_ZER;
}
