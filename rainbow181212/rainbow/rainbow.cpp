#include "sizes.h"
#include "Compose.h"
#include "cycles.h"

using namespace std;

int main()
{
	unsigned char sk[SECRETKEY_BYTES]; unsigned long sklen;
	unsigned char pk[PUBLICKEY_BYTES]; unsigned long pklen;
	unsigned char m[SHORTMESSAGE_BYTES]; unsigned long long mlen = nv1 ;
	unsigned char sm[SIGNATURE_BYTES] ; unsigned long long smlen = ovn ;
	
	int i, eof ;
	uint64_t initial_key_pair = rdtsc();
	i=keypair( sk, & sklen, pk, & pklen ) ; //TODO: keypair function should take random inputs or inputs from a fil
	uint64_t final_key_pair = rdtsc();
	uint64_t key_pair_count = final_key_pair - initial_key_pair;

	printf("cycles keypair: %d \n", key_pair_count);

	srand(100);
#if DEBUG > 0
	cout << "\nmessage: ";
#endif
	for ( i = 0 ; i < nv1; i++ ) {
		m[i] = rand() % deg_pow; // pow = 256;
#if DEBUG > 0
		cout << GFpow(m[i])<<" ";
#endif
	}
#if DEBUG > 0	
	cout << endl ;
#endif
	uint64_t initial_enc = rdtsc();
	eof = signedshortmessage( sm, &smlen, m, mlen, sk, sklen);
	uint64_t final_enc = rdtsc();

	uint64_t enc_count = final_enc - initial_enc;

	printf("cycles signedshortmessage: %d \n", enc_count);

	if (eof < 0)
	{
		cout << "Could not sign message" << endl;
		return -1;
	}
	else
#if DEBUG > 0
	cout << "\nSignature: " ;
	for (i = 0; i < ovn; i++) cout << GFpow(sm[i]) << " "; // signed message
#endif

	initial_enc = rdtsc();
	eof = shortmessagesigned( m,& mlen, sm, smlen, pk, pklen);
	final_enc = rdtsc();
	enc_count = final_enc - initial_enc;
	printf("cycles shortmessagesigned: %d \n", enc_count);

#if DEBUG > 0
	cout << endl << eof << endl;
#endif

	return eof;
}
