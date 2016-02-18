#include "bi_intl.h"

#define bii_hex_val_lookup(c) 	((c == '0') ? 0x0 : \
								((c == '1') ? 0x1 : \
								((c == '2') ? 0x2 : \
								((c == '3') ? 0x3 : \
								((c == '4') ? 0x4 : \
								((c == '5') ? 0x5 : \
								((c == '6') ? 0x6 : \
								((c == '7') ? 0x7 : \
								((c == '8') ? 0x8 : \
								((c == '9') ? 0x9 : \
								((c == 'a') ? 0xa : \
								((c == 'b') ? 0xb : \
								((c == 'c') ? 0xc : \
								((c == 'd') ? 0xd : \
								((c == 'e') ? 0xe : \
								((c == 'f') ? 0xf : 0x10))))))))))))))))
												

void bi_init_hex(bigint *b, const char *hex){
	size_t len = strlen(hex);
	if(len==0){
		bi_set_u32(b,0);
		return;
	}
	
	bi_init_len(b, ((len-1)>>3)+1);
			
	char *nhex = hex;
	if(hex[0] == '-'){
		nhex++;
		len--;
		bi_set_neg(b);
	} else{
		bi_set_pos(b);
	}
	
	if(len>2 && nhex[1]=='x'){
		nhex+=2;
		len-=2;
	}

	char c;
	for(size_t i=0; i<len; i++){
		c = bii_hex_val_lookup(nhex[len-i-1]);
		assert((c != 0x10) && "Invalid hex character\n");
		b->val[(i>>3)] |= ((uint32_t)(c)) << ((i&7)<<2);
	}
}
