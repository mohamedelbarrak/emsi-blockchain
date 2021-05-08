#include "hblk_crypto.h"

/**
 * ec_from_pub - create an EC_KEY structure
 * Return: pointer to created EC_KEY
 */
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN])
{
	EC_KEY *keyPr;
	EC_GROUP *group;
	EC_POINT *pt;
	if (pub == NULL)
		return (NULL);
		
	keyPr = EC_KEY_new_by_curve_name(EC_CURVE);
	if (keyPr== NULL)
		return (NULL);
		
	group = (EC_GROUP *)EC_KEY_get0_group(keyPr);
	pt = EC_POINT_new(group);
	if (pt == NULL)
	{
		EC_KEY_free(keyPr);
		return (NULL);
	}
	
	if (!EC_POINT_oct2point(group, pt, pub, EC_PUB_LEN, NULL))
		goto clean;
		
	if (!EC_KEY_set_public_key(keyPr, pt))
		goto clean;
		
	EC_POINT_free(pt);
	return (keyPr);
clean:
	EC_KEY_free(keyPr);
	EC_POINT_free(pt);
	return (NULL);
}

