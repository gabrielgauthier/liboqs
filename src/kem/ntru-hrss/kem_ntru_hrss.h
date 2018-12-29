#ifndef __OQS_KEM_NTRU_HRSS_H
#define __OQS_KEM_NTRU_HRSS_H

#include <oqs/oqs.h>

#ifdef OQS_ENABLE_KEM_ntru_hrss

#define OQS_KEM_ntru_hrss_length_public_key 1138
#define OQS_KEM_ntru_hrss_length_secret_key 1418
#define OQS_KEM_ntru_hrss_length_ciphertext 1278
#define OQS_KEM_ntru_hrss_length_shared_secret 32

OQS_KEM *OQS_KEM_ntru_hrss_new();

OQS_STATUS OQS_KEM_ntru_hrss_keypair(uint8_t *public_key, uint8_t *secret_key);
OQS_STATUS OQS_KEM_ntru_hrss_encaps(uint8_t *ciphertext, uint8_t *shared_secret, const uint8_t *public_key);
OQS_STATUS OQS_KEM_ntru_hrss_decaps(uint8_t *shared_secret, const unsigned char *ciphertext, const uint8_t *secret_key);

#endif

#endif /* __OQS_KEM_NTRU_HRSS */
