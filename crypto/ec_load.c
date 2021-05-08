#include "hblk_crypto.h"

/**
 * ec_load - load an EC key pair from the disk
 *
 * @folder: path to folder from which to load the keys
 *
 * Return: creat EC key
 */
EC_KEY *ec_load(char const *folder)
{
	FILE *fp;
	EC_KEY *keyPr;
	char path[BUFSIZ];
	
	if (!folder)
		return (NULL);
		
	sprintf(path, "%s/%s", folder, PUB_FILENAME);
	fp = fopen(path, "r");
	if (!fp)
	{
		EC_KEY_free(keyPr);
		return (0);
	}
	if (!PEM_read_EC_PUBKEY(fp, &keyPr, NULL, NULL))
		return (NULL);
		
	fclose(fp);
	sprintf(path, "%s/%s", folder, PRI_FILENAME);
	fp = fopen(path, "r");
	if (!PEM_read_ECPrivateKey(fp, &keyPr, NULL, NULL))
		return (NULL);
		
	fclose(fp);
	return (keyPr);
}

