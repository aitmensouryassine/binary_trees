#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of heap
 * Return: the value stored in the root node
 */
int heap_extract(heap_t **root)
{
	if (!root)
		return (0);

	return ((*root)->n);
}
