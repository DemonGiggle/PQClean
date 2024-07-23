#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "api.h"

#define PUBLIC_KEY_BYTES    PQCLEAN_DILITHIUM5_CLEAN_CRYPTO_PUBLICKEYBYTES
#define SECRET_KEY_BYTES    PQCLEAN_DILITHIUM5_CLEAN_CRYPTO_SECRETKEYBYTES
#define CRYPTO_BYTES        PQCLEAN_DILITHIUM5_CLEAN_CRYPTO_BYTES

static void printbytes(
		const char *prelog, 
		const uint8_t *bytes, 
		size_t len)
{
	size_t i;

	printf("%s", prelog);
	
	for (i = 0; i < len; i++) {
		printf("%02x", bytes[i]);
	}

	printf("\n");
}

static void write_key(
		const char *fname,
		const uint8_t *bytes,
		size_t len)
{
	FILE *fp;
	size_t i;

	fp = fopen(fname, "w");
	for (i = 0; i < len; i++) {
		fprintf(fp, "%02x", bytes[i]);
	}

	fclose(fp);
}

static void rand_msg(uint8_t *msg, size_t msg_len)
{
	size_t i;

	srand((unsigned) time(NULL));

	for (i = 0; i < msg_len; i++) {
		msg[i] = rand() % 256;
	}
}

int main()
{
	uint8_t pk[PUBLIC_KEY_BYTES] = {0};
	uint8_t sk[SECRET_KEY_BYTES] = {0};
	uint8_t sig[CRYPTO_BYTES] = {0};
	uint8_t msg[1024] = {0};
	size_t  sig_len;

	rand_msg(msg, sizeof(msg));

    if (PQCLEAN_DILITHIUM5_CLEAN_crypto_sign_keypair(pk, sk) != 0) {
	    printf("Keygen: Fail\n");
	    return -1;
    }

    printbytes("pk=", pk, sizeof(pk));
    printbytes("sk=", sk, sizeof(sk));

	// Let's check the keys are usable
	if (PQCLEAN_DILITHIUM5_CLEAN_crypto_sign_signature(
				sig, &sig_len, msg, sizeof(msg), sk) != 0) {
		printf("Sign: Fail\n");
		return -1;
	}

	if (PQCLEAN_DILITHIUM5_CLEAN_crypto_sign_verify(
				sig, sig_len, msg, sizeof(msg), pk) != 0) {
		printf("Verify: Fail\n");
		return -1;
	}

	// Now, we could write down the keys
	write_key("pk.txt", pk, sizeof(pk));
	write_key("sk.txt", sk, sizeof(sk));

	return 0;
}
