#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * to insert the value
 * @value: the value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (root == NULL || !value)
		return (NULL);

	return (*root);
}
