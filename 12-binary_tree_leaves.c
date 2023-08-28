#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: The number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t num = 0;

	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	num += binary_tree_leaves(tree->left);
	num += binary_tree_leaves(tree->right);

	return (num);
}
