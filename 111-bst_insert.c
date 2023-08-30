#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST
 * to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		if (!new)
			return (NULL);

		*tree = new;
		return (new);
	}

	if ((*tree)->n > value)
	{
		if ((*tree)->left != NULL)
			return (bst_insert(&((*tree)->left), value));

		new = binary_tree_node(*tree, value);
		if (!new)
			return (NULL);
		(*tree)->left = new;

		return (new);
	}
	else if ((*tree)->n < value)
	{
		if ((*tree)->right != NULL)
			return (bst_insert(&((*tree)->right), value));

		new = binary_tree_node(*tree, value);
		if (!new)
			return (NULL);
		(*tree)->right = new;

		return (new);
	}
	return (NULL);
}
