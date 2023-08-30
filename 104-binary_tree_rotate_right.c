#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: is a pointer to the root node of the tree to rotate
 * Return: return a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *tmp = NULL, *swap = NULL;

	if (!tree || !(tree->left))
		return (NULL);

	/* set new root */
	new_root = tree->left;
	/* get right child if exist */
	tmp = new_root->right;
	/* set tree to the right of the new root */
	new_root->right = tree;
	/* set tmp the original right to tree left */
	tree->left = tmp;

	/* if tmp exists we set its parent to tree */
	if (tmp)
		tmp->parent = tree;

	/* swap the parents of the new and the old root */
	swap = tree->parent;
	tree->parent = new_root;
	new_root->parent = swap;

	/* if tree had a parent, we set new_root in the correct branch */
	if (swap)
	{
		if (swap->left == tree)
			swap->left = new_root;
		else
			swap->right = new_root;
	}

	return (new_root);
}
