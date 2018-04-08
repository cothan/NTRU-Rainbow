
CC = gcc
OBJ = test_common.o ntru_crypto_drbg.o ntru_crypto_hmac.o ntru_crypto_msbyte_uint32.o ntru_crypto_hash.o ntru_crypto_sha1.o ntru_crypto_sha2.o ntru_crypto_sha256.o ntru_crypto_ntru_convert.o ntru_crypto_ntru_mult_indices_simd.o ntru_crypto_ntru_mgf1.o ntru_crypto_ntru_mult_coeffs_simd.o ntru_crypto_ntru_poly.o ntru_crypto_ntru_encrypt_param_sets.o ntru_crypto_ntru_encrypt.o ntru_crypto_ntru_encrypt_key.o cpucycles.o bench.o 
LIBS = -L. -L/usr/lib
BIN = bench
CFLAGS = -c -Wall -I.  -O3
RM = rm -f 

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) -O3 $(OBJ) -o $(BIN) $(LIBS) -mtune=native -march=native


test_common.o : test_common.c
	$(CC) -c test_common.c -o test_common.o $(CFLAGS)

ntru_crypto_drbg.o : ntru_crypto_drbg.c
	$(CC) -c ntru_crypto_drbg.c -o ntru_crypto_drbg.o $(CFLAGS)

ntru_crypto_hmac.o : ntru_crypto_hmac.c 
	$(CC) -c ntru_crypto_hmac.c -o ntru_crypto_hmac.o $(CFLAGS)

ntru_crypto_msbyte_uint32.o : ntru_crypto_msbyte_uint32.c 
	$(CC) -c ntru_crypto_msbyte_uint32.c -o ntru_crypto_msbyte_uint32.o $(CFLAGS)

ntru_crypto_hash.o : ntru_crypto_hash.c 
	$(CC) -c ntru_crypto_hash.c -o ntru_crypto_hash.o $(CFLAGS)

ntru_crypto_sha1.o : ntru_crypto_sha1.c 
	$(CC) -c ntru_crypto_sha1.c -o ntru_crypto_sha1.o $(CFLAGS)

ntru_crypto_sha2.o : ntru_crypto_sha2.c 
	$(CC) -c ntru_crypto_sha2.c -o ntru_crypto_sha2.o $(CFLAGS)

ntru_crypto_sha256.o : ntru_crypto_sha256.c 
	$(CC) -c ntru_crypto_sha256.c -o ntru_crypto_sha256.o $(CFLAGS)

ntru_crypto_ntru_convert.o : ntru_crypto_ntru_convert.c   
	$(CC) -c ntru_crypto_ntru_convert.c  -o ntru_crypto_ntru_convert.o $(CFLAGS)

ntru_crypto_ntru_mult_indices_simd.o : ntru_crypto_ntru_mult_indices_simd.c 
	$(CC) -mavx2 -c ntru_crypto_ntru_mult_indices_simd.c -o ntru_crypto_ntru_mult_indices_simd.o $(CFLAGS)

ntru_crypto_ntru_mgf1.o : ntru_crypto_ntru_mgf1.c 
	$(CC) -c ntru_crypto_ntru_mgf1.c -o ntru_crypto_ntru_mgf1.o $(CFLAGS)

ntru_crypto_ntru_mult_coeffs_simd.o : ntru_crypto_ntru_mult_coeffs_simd.c 
	$(CC) -mavx2 -c ntru_crypto_ntru_mult_coeffs_simd.c -o ntru_crypto_ntru_mult_coeffs_simd.o $(CFLAGS)


ntru_crypto_ntru_poly.o : ntru_crypto_ntru_poly.c
	$(CC) -c ntru_crypto_ntru_poly.c -o ntru_crypto_ntru_poly.o $(CFLAGS)




ntru_crypto_ntru_encrypt_param_sets.c : ntru_crypto_ntru_encrypt_param_sets.o 
	$(CC) -c ntru_crypto_ntru_encrypt_param_sets.c -o ntru_crypto_ntru_encrypt_param_sets.o $(CFLAGS)


ntru_crypto_ntru_encrypt.o : ntru_crypto_ntru_encrypt.c 
	$(CC) -c ntru_crypto_ntru_encrypt.c -o ntru_crypto_ntru_encrypt.o $(CFLAGS)
ntru_crypto_ntru_encrypt_key.o : ntru_crypto_ntru_encrypt_key.c 
	$(CC) -c ntru_crypto_ntru_encrypt_key.c -o ntru_crypto_ntru_encrypt_key.o $(CFLAGS)


cpucycles.o: cpucycles.c 
	$(CC) -c cpucycles.c -o cpucycles.o $(CFLAGS)

bench.o : bench.c 
	$(CC) -c bench.c -o bench.o $(CFLAGS)
