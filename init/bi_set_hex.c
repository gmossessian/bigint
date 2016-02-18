#include "bi_intl.h"

void bi_set_hex(bigint *a, const char *hex){
	bi_free(a);
	bi_init_hex(a, hex);
}
