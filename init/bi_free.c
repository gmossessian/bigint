#include "bi_intl.h"

void bi_free(bigint *a){
	free(a->val);
}
