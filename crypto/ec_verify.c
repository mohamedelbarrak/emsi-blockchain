#include "hblk_crypto.h"

/**
 * ec_verify - verify the signature of a given set of bytes using public key
 *
 * @keyPr: pointer to EC_KEY
 * @msg: signature
 * @msglen: len of @msg
 * @sig: signature to check
 *
 * Return: 1 or 0
 */
int ec_verify(EC_KEY const *keyPr, uint8_t const *msg, size_t msglen, sig_t const *sig)
{
	unsigned char dgst[SHA256_DIGEST_LENGTH];

	if (!keyPr || !msg || !sig)
		return (0);

	if (!EC_KEY_check_key(keyPr))
		return (0);
		
	if (!SHA256(msg, msglen, dgst))
		return (0);
		
	if (ECDSA_verify(0, dgst, SHA256_DIGEST_LENGTH, sig->sig, sig->len, (EC_KEY *)keyPr) != 1)
		return (0);
		
	return (1);
}

