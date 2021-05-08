#include "blockchain.h"

/**
 */
void block_destroy(block_t *block)
{
	free(block);
}

