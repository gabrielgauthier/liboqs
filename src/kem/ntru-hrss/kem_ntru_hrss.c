#include <stdlib.h>

#include <oqs/kem_ntru_hrss.h>

#ifdef OQS_ENABLE_KEM_ntru_hrss

OQS_KEM *OQS_KEM_ntru_hrss_new() {

	OQS_KEM *kem = malloc(sizeof(OQS_KEM));
	if (kem == NULL) {
		return NULL;
	}
	kem->method_name = OQS_KEM_alg_ntru_hrss;

	kem->claimed_nist_level = 1;
	kem->ind_cca = true;

	kem->length_public_key = OQS_KEM_ntru_hrss_length_public_key;
	kem->length_secret_key = OQS_KEM_ntru_hrss_length_secret_key;
	kem->length_ciphertext = OQS_KEM_ntru_hrss_length_ciphertext;
	kem->length_shared_secret = OQS_KEM_ntru_hrss_length_shared_secret;

	// redirection: link up externally defined API functions to KEM struct
	kem->keypair = OQS_KEM_ntru_hrss_keypair;
	kem->encaps = OQS_KEM_ntru_hrss_encaps;
	kem->decaps = OQS_KEM_ntru_hrss_decaps;

	return kem;
}

#endif /* OQS_ENABLE_KEM_ntru_hrss */
