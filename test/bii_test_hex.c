#include "bi_test.h"

int bii_test_hex(void){
	bigint r;
	bi_init_hex(&r, "0123456789abcdef");
	if(r.len != 2){
		fprintf(stderr, "bii_test_hex test 1.1 failed:\nr.len = %zu != 2.\n", r.len);
		return 1;
	}
	if(r.val[0]!=0x89abcdef){
		fprintf(stderr, "bii_test_hex test 1.2 failed:\n\r.val[0] = 0x%08x != 0x89abcdef", r.val[0]);
		return 1;
	}
	if(r.val[1]!=0x01234567){
		fprintf(stderr, "bii_test_hex test 1.3 failed:\n\r.val[1] = 0x%08x != 0x01234567", r.val[1]);
		return 1;
	}
	if(r.sgn != BI_POS){
		fprintf(stderr, "bii_test_hex test 1.4 failed:\nr.sgn = %i != %i", r.sgn, BI_POS);
		return 1;
	}
	
	bi_set_hex(&r,"0x0123456789abcdef012345");
	if(r.len != 3){
		fprintf(stderr, "bii_test_hex test 2.1 failed:\nr.len = %zu != 3.\n", r.len);
		return 1;
	}
	if(r.val[0]!=0xef012345){
		fprintf(stderr, "bii_test_hex test 2.2 failed:\n\r.val[0] = 0x%08x != 0x89abcdef", r.val[0]);
		return 1;
	}
	if(r.val[1]!=0x6789abcd){
		fprintf(stderr, "bii_test_hex test 2.3 failed:\n\r.val[1] = 0x%08x != 0x01234567", r.val[1]);
		return 1;
	}
	if(r.val[2]!=0x012345){
		fprintf(stderr, "bii_test_hex test 2.4 failed:\n\r.val[1] = 0x%08x != 0x01234567", r.val[2]);
		return 1;
	}
	if(r.sgn != BI_POS){
		fprintf(stderr, "bii_test_hex test 2.5 failed:\nr.sgn = %i != %i", r.sgn, BI_POS);
		return 1;
	}

	return 0;
}
