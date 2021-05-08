#include "blockchain.h"

/**
 * block_create - creates a new block in the sequence
 * @prev: pointer to previous block
 * @data: pointer of data to duplicate
 * @data_len: length of data
 * Return: pointer to new block or NULL
 */
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len)
	{
	block_t *blk;
	blk = calloc(1, sizeof(*blk));
	if (blk == NULL)
		return (NULL);

	blk->info.index = prev->info.index + 1;
	blk->info.difficulty = 0;
	blk->info.timestamp = time(NULL);
	blk->info.nonce = 0;
	memcpy(blk->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
	memcpy(blk->data.buffer, data, data_len);
	blk->data.len = data_len;
	memset(blk->hash, 0, SHA256_DIGEST_LENGTH);
	
	return (blk);

	}
	
