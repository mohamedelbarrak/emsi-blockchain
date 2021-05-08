#include "hblk_crypto.h"

/**
 * ec_save - save pub/private key pair into a file
 * @folder: directory where to store the file
 * Return: 1 or 0
 */
int ec_save(EC_KEY *keyPr, char const *folder)
{
	FILE *fp;
	char path[BUFSIZ];

	if (!keyPr || !folder)
		return (0);
	mkdir(folder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	sprintf(path, "%s/" PRV_FILE, folder);
	fp = fopen(path, "w");
	if (!fp)
		return (0);
		
	if (!PEM_write_ECPrivateKey(fp, keyPr, NULL, NULL, 0, NULL, NULL))
	{
		fclose(fp);
		return (0);
	}
	
	fclose(fp);
	sprintf(path, "%s/" PUB_FILE, folder);
	fp = fopen(path, "w");
	
	if (!fp)
		return (0);
	if (!PEM_write_EC_PUBKEY(fp, keyPr))
	goto out;
		fclose(fp);
		return (0);
	
	out:
	fclose(fp);
	return (1);
}

