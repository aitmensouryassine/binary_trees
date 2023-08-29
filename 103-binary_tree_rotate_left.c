#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: return a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp = NULL;

	if (!tree || !(tree->right))
		return (NULL);

	new_root = tree->right;

	if (new_root->left)
		tmp = new_root->left;

	new_root->left = tree;
	new_root->parent = NULL;
	new_root->left->parent = new_root;

	if (new_root->left->left == NULL)
	{
		new_root->left->left = tmp;
		new_root->left->right = NULL;
	}
	else
		new_root->left->right = tmp;

	return (new_root);
}
