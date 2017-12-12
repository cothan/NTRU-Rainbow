#ifndef NTRU_TEST_COMMON_H
#define NTRU_TEST_COMMON_H

/* Common components for all test programs */

uint32_t randombytes(uint8_t *x,uint32_t xlen);


/* HMAC SHA256 entropy functions */
uint8_t
drbg_sha256_hmac_get_entropy(ENTROPY_CMD cmd, uint8_t *out);

uint8_t
drbg_sha256_hmac_get_entropy_err_init(ENTROPY_CMD cmd, uint8_t *out);

uint8_t
drbg_sha256_hmac_get_entropy_err_get_num(ENTROPY_CMD cmd, uint8_t *out);

uint8_t
drbg_sha256_hmac_get_entropy_err_num_eq_zero(ENTROPY_CMD cmd, uint8_t *out);

uint8_t
drbg_sha256_hmac_get_entropy_err_get_byte(ENTROPY_CMD cmd, uint8_t *out);

/* List of parameter sets */

static const NTRU_ENCRYPT_PARAM_SET_ID PARAM_SET_IDS[] = {
    NTRU_EES1499EP1};
#define NUM_PARAM_SETS (sizeof(PARAM_SET_IDS)/sizeof(PARAM_SET_IDS[0]))

#endif
