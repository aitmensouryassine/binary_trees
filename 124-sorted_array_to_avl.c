#include "binary_trees.h"

/**
 * sort_array_to_avl_rec - create avl binary tree from a sorted array
 * @array: the giving array
 * @start: the first index of the array
 * @end: the last index of the array
 * @parent: pointer to the parent of a created node
 * Return: the created tree
 */
avl_t *sort_array_to_avl_rec(int *array, int start, int end, avl_t *parent)
{
	int middle = 0;
	avl_t *tree = NULL;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	tree = binary_tree_node(parent, array[middle]);
	if (!tree)
		return (NULL);
	tree->left = sort_array_to_avl_rec(array, start, middle - 1, tree);
	tree->right = sort_array_to_avl_rec(array, middle + 1, end, tree);

	return (tree);
}


/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);

	return (sort_array_to_avl_rec(array, 0, (int)size - 1, NULL));
}
