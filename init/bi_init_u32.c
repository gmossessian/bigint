#include "bi_intl.h"

void bi_init_u32(bigint *r, uint32_t i){
	/*
	 * Initalize a bigint from an unsigned 32-bit integer
	 */
	bi_init_len(r,1);
	if(i!=0) bi_set_pos(r);
	r->val[0] = i;
}
