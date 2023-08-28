#include "binary_trees.h"

/**
 * binary_tree_full_rec - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is full or 0
 */
int binary_tree_full_rec(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if ((tree->left && tree->right == NULL) ||
			(tree->right && tree->left == NULL) ||
			binary_tree_full_rec(tree->left) == 0 ||
			binary_tree_full_rec(tree->right) == 0)
		return (0);
	return (1);
}


/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is full or 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_full_rec(tree));
}
