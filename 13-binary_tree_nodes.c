#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in
 * a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: nbr of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nbr_nodes = 0;

	if (!tree)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		nbr_nodes = 1;

	nbr_nodes += binary_tree_nodes(tree->left);
	nbr_nodes += binary_tree_nodes(tree->right);

	return (nbr_nodes);
}
