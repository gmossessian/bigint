#include "bi_intl.h"

uint8_t bii_free_tmp(bigint *tmp){
	uint8_t i;
	for(i=0; i<bii_ntmp; i++){
		if(&(bii_tmp_vars[i]) == tmp) break;
	}
	if(i == bii_ntmp){
		return 1;
	}
	if(bii_tmp_avail[i] == 1){
		return 1;
	}
	bii_tmp_avail[i] = 1;
	return 0;
}
