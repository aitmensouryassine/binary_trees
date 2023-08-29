#include "binary_trees.h"
#include <stdio.h>

/**
 * bt_height_n_nodes - Calculates the height difference of left and right nodes
 * and number of nodes in a binary tree
 * @tree: is a pointer to the root node of the tree to check
 * @n_nodes: A pointer to number of nodes
 * Return: The height difference of left and right nodes
 */
int bt_height_n_nodes(const binary_tree_t *tree, int *n_nodes)
{
	int lh, rh;

	if (!tree)
		return (0);

	(*n_nodes)++;
	lh = tree->left ? 1 + bt_height_n_nodes(tree->left, n_nodes) : 0;
	rh = tree->right ? 1 + bt_height_n_nodes(tree->right, n_nodes) : 0;

	return (lh - rh);
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lh, rh, l_num_nodes = 0, r_num_nodes = 0;

	if (!tree)
		return (0);

	lh = bt_height_n_nodes(tree->left, &l_num_nodes);
	rh = bt_height_n_nodes(tree->right, &r_num_nodes);

	if (lh == rh && l_num_nodes == r_num_nodes)
		return (1);
	return (0);
}
