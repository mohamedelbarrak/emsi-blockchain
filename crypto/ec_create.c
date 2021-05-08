#include "hblk_crypto.h"
#include <stdlib.h>
/**
 * ec_create - creates a new EC key pair
 *
 * Return: pointer to created 
 */
EC_KEY *ec_create(void)
{
	
	EC_KEY *keyPr = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!keyPr)
		return (NULL);
	if (!EC_KEY_generate_key(keyPr))
	{
		EC_KEY_free(keyPr);
		return (NULL);
	}
	return (keyPr);
}

