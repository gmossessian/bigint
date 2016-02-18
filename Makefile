CC = clang

H_DIR = ./headers
INIT_DIR = ./init
TEST_DIR = ./test
TMP_DIR = ./tmp
UTIL_DIR = ./util

ALL_C = $(INIT_DIR)/*.c $(TEST_DIR)/*.c $(TMP_DIR)/*.c $(UTIL_DIR)/*.c

all: 
	$(CC) -o bi_test.out -Wall -I$(H_DIR) $(ALL_C)
