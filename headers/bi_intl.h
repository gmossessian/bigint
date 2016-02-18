#pragma once

#include "bi.h"
#include <assert.h>
#include <time.h>
#include <sys/time.h>

#define bii_sigbits(b) (bii_sigbits32(b.val[0])+((b.len-1)<<5))

bigint *bii_tmp_vars = NULL;
uint8_t *bii_tmp_avail = NULL;
uint8_t bii_ntmp=0;

bigint *bii_get_tmp(void);
uint8_t bii_free_tmp(bigint *tmp);

void bii_cat(bigint *dest, const bigint cat);
char bii_cmp(const bigint a, const bigint b);

uint8_t bii_sigbits32(uint32_t a);
uint32_t bii_ispowerof2(const bigint a);
void bii_stripzeroes(const bigint a);

void bii_rshift(bigint *dest, const bigint a, const size_t nbits);
void bii_lshift(bigint *dest, const bigint a, const size_t nbits);
void bii_mul(bigint *dest, const bigint a, const bigint b);
void bii_add(bigint *dest, const bigint a, const bigint b);
void bii_sub(bigint *dest, const bigint a, const bigint b);
void bii_div(bigint *q, bigint *r, const bigint a, const bigint b);

void bii_add_eq(bigint *a, const bigint b);
void bii_sub_eq(bigint *a, const bigint b);
void bii_mul_eq(bigint *a, const bigint b);
void bii_mod_eq(bigint *a, const bigint b);

void bii_egcd(bigint *x, bigint *y, const bigint a, const bigint b, const bigint c);
void bii_powm(bigint *dest, const bigint b, const bigint e, const bigint m);
