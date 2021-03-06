#include "hblk_crypto.h"

/**
 * ec_sign - sign a set of bytes, using given private EC_KEY
 * @msg: pointer to characters to be signed
 * @msglen: len of msg
 * @sig: address to store signature
 *
 * Return: pointer to signature buffer on success, NULL on error
 */
uint8_t *ec_sign(EC_KEY const *keyPr, uint8_t const *msg, size_t msglen,
		sig_t *sig)
{
	unsigned char md[SHA256_DIGEST_LENGTH];

	if (!keyPr || !msg || !sig)
		return (NULL);
		
	if (!EC_KEY_check_key(keyPr))
		return (NULL);
		
	if (!SHA256(msg, msglen, md))
		return (NULL);
	sig->len = ECDSA_size(keyPr);
	if (!sig->len)
		return (NULL);
		
	if (!ECDSA_sign(EC_CURVE, md, SHA256_DIGEST_LENGTH, sig->sig, (unsigned int *)&(sig->len), (EC_KEY *)keyPr))
		return (NULL);
		
	return (sig->sig);
}

