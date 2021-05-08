#include "hblk_crypto.h"

/**
 * ec_to_pub - extracts public key from EC_KEY struct
 * @keyPr: pointer to EC_KEY struct
 */

uint8_t *ec_to_pub(EC_KEY const *keyPr, uint8_t pub[EC_PUB_LEN])
{
	const EC_GROUP *gp;
	const EC_POINT *pt;

	if (!keyPr)
		return (NULL);

		gp = EC_KEY_get0_group(keyPr);
		pt = EC_KEY_get0_public_key(keyPr);

	if (!gp || !pt)
		return (NULL);

	if (!EC_POINT_point2oct(gp, pt, EC_KEY_get_conv_form(keyPr), pub, EC_PUB_LEN, NULL))
		return (NULL);

	return (pub);
}

