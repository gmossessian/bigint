#include "bi_intl.h"

bigint *bii_get_tmp(void){
	/*
	 * Return a pointer to the first available tmp variable in the global array list bii_tmp_vars
	 * If none are available, add a new one and return that
	 */
	if(bii_tmp_vars == NULL){
		bii_ntmp = 1;
		bii_tmp_vars = calloc(1, sizeof(bigint));
		bii_tmp_avail = calloc(1, sizeof(uint8_t));
		bi_init(&(bii_tmp_vars[0]));
		bii_tmp_avail[0] = 0;
		return bii_tmp_vars;
	}
	
	uint8_t i;
	for(i=0; i < bii_ntmp; i++){
		if(bii_tmp_avail[i] == 1){
			break;
		}
	}
	if(i==bii_ntmp){
		bii_ntmp++;
		
		bii_tmp_vars = realloc(bii_tmp_vars, bii_ntmp*sizeof(bigint));
		bii_tmp_avail = realloc(bii_tmp_avail, bii_ntmp*sizeof(uint8_t));
		
		bi_init(&(bii_tmp_vars[bii_ntmp-1]));
		bii_tmp_avail[bii_ntmp-1]=1;
	}
	
	bii_tmp_avail[i] = 0;
	return &(bii_tmp_vars[i]);
}
