#include "binary_trees.h"
#include <stdio.h>

/**
 * in_order_successor - get in order successor of a node
 * @root: a pointer to the node to search for it's in order successor
 * Return: a pointer to the "in order successor" of the given node
 */
bst_t *in_order_successor(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

/**
 * parent - looks for the parent of a node
 * @node: a pointer to the node
 * Return: A pointer to the parent of the node
 */
bst_t *parent(bst_t *node)
{
	if (node->parent == NULL)
		return (node);
	return (parent(node->parent));
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: is a pointer to the root node of the tree where
 * you will remove a node
 * @value: is the value to remove in the tree
 * Return: a pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *tmp;
	int tmp_n;

	if (!root || !value)
		return (NULL);
	if (root->n == value)
	{
		if (root->right == NULL)
		{
			if (root->left)
				root->left->parent = root->parent;
			if (root->parent && root->parent->left == root)
				root->parent->left = root->left;
			else if (root->parent)
				root->parent->right = root->left;
			tmp = parent(root);
			free(root);
			return (tmp);
		}
		if (root->left == NULL)
		{
			if (root->right)
				root->right->parent = root->parent;
			if (root->parent && root->parent->right == root)
				root->parent->right = root->right;
			else if (root->parent)
				root->parent->left = root->right;
			tmp = parent(root);
			free(root);
			return (tmp);
		}
		node = in_order_successor(root->right);
		tmp_n = node->n;
		bst_remove(parent(node), node->n);
		root->n = tmp_n;
		return (parent(root));
	}
	else if (root->n < value)
		return (bst_remove(root->right, value));
	return (bst_remove(root->left, value));
}
