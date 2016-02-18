#include "bi_intl.h"

void bi_init_rnd(bigint *r, uint32_t nbits){
	bi_init_len(r, ((nbits-1)>>5)+1);
	uint32_t mask = ((((uint64_t)1)<<(32-((32-(nbits&31))&31)))-1)&0xFFFFFFFF;
	r->val[0] = (((rand()&0xFFFF) << 16) | (rand()&0xFFFFF))&mask;
	for(uint32_t i = 1; i<r->len; i++){
		r->val[i] =  ((rand()&0xFFFF) << 16) | (rand()&0xFFFFF);
	}
	bi_set_pos(r);
}

