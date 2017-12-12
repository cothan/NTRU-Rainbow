#include "crypto_sign.h"
#include "Compose.h"
#include "sizes.h"
#include "crypto_hash_sha256.h"


// TODO: rand() source

int crypto_sign_keypair(
    unsigned char *pk,
    unsigned char *sk
)
{
    unsigned long sklen;
    unsigned long pklen;
    return keypair(sk, &sklen, pk, &pklen);
}

int crypto_sign(
    unsigned char *sm, unsigned long long *smlen,
    const unsigned char *m, unsigned long long mlen,
    const unsigned char *sk
)
{
    unsigned long sklen = SECRETKEY_BYTES;

    // Hash input message
    unsigned char h[32];
    crypto_hash_sha256(h,m,mlen);

    // Sign hashed message
    int res = signedshortmessage(sm, smlen, h, SHORTMESSAGE_BYTES, sk, sklen);
    //printf("crypto_sign MLen %d Signed message len %d \n", mlen, *smlen);
#if DEBUG > 0
    printf("----------------------------------------------------------------\n");
    printf("Hash input ");
    for(int i = 0; i < 32; i++){
    	printf("%d, ",h[i]);
    }
    printf("\n");
    printf("Signature ");
    for(int i = 0; i < *smlen; i++){
        printf("%d, ",sm[i]);
    }
    printf("\n");
#endif
    if (res < 0)
    {
        return -1;
    }

    // Append message to signature
    for (int i = 0; i < mlen; ++i) {
        sm[*smlen] = m[i];
        ++*smlen;
     }
    return 0;
}

int crypto_sign_open(
    unsigned char *m, unsigned long long *mlen,
    const unsigned char *sm, unsigned long long smlen,
    const unsigned char *pk
)
{
    unsigned long pklen = PUBLICKEY_BYTES;

    // Hash input message
    unsigned char h[32];
    crypto_hash_sha256(h, sm + SIGNATURE_BYTES, smlen - SIGNATURE_BYTES);

    int res = shortmessagesigned(h, mlen, sm, SIGNATURE_BYTES, pk, pklen);
    //printf("crypto_sign_open Message len %d , res %d \n", *mlen, res);
    if (res < 0)
    {
        return -1;
    }

    for (unsigned int i = SIGNATURE_BYTES;i < smlen;++i) m[i - SIGNATURE_BYTES] = sm[i];
      *mlen = smlen - SIGNATURE_BYTES;
    return 0;
}
