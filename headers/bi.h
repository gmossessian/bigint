#pragma once

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

#define BI_NEG -1
#define BI_ZER 0
#define BI_POS 1

#define BII_LT -2
#define BII_LE -1
#define BII_EQ 0
#define BII_GT 1
#define BII_GE 2

typedef struct bigint{
	uint32_t *val;
	size_t len;
	int8_t sgn;
}bigint;

//initialization
void bi_init(bigint *r);
void bi_init_len(bigint *r, const size_t len);
void bi_init_u32(bigint *r, const uint32_t i);
void bi_init_hex(bigint *r, const char *hex);
void bi_init_rnd(bigint *r, const uint32_t nbits);

//dei-initialization
void bi_free(bigint *a);

//set initialized bigint
void bi_set(bigint *dest, const bigint src);
void bi_set_u32(bigint *dest, const uint32_t val);
void bi_set_hex(bigint *dest, const char *hex);
void bi_set_rnd(bigint *dest, const uint32_t nbits);

//string conversions
void bi_get_hex(char **buf, const bigint a);

//basic utilities
int8_t bi_cmp(const bigint a, const bigint b);
int8_t bi_cmp_u32(const bigint a, const uint32_t val);
uint8_t bi_parity(const bigint a); 
void bi_add_eq(bigint *a, const bigint b);
void bi_sub_eq(bigint *a, const bigint b);
void bi_mul_eq(bigint *a, const bigint b);
void bi_mod_eq(bigint *a, const bigint b);
void bi_incr(bigint *a);
void bi_decr(bigint *a);
void bi_getsigbits(bigint *dest, const bigint a, const size_t nbits);
void bi_set_neg(bigint *b);
void bi_set_pos(bigint *b);
void bi_set_zer(bigint *b);
void bi_negate(bigint *b);

//arithmetic
void bi_rshift(bigint *dest, const bigint a, const size_t nbits);
void bi_lshift(bigint *dest, const bigint a, const size_t nbits);
void bi_add(bigint *dest, const bigint a, const bigint b);
void bi_sub(bigint *dest, const bigint a, const bigint b);
void bi_mul(bigint *dest, const bigint a, const bigint b);
void bi_div(bigint *q, bigint *r, const bigint a, const bigint b);

//number theory
void bi_egcd(bigint *x, bigint *y, const bigint a, const bigint b, const bigint c);
void bi_powm(bigint *dest, const bigint b, const bigint e, const bigint mod);
