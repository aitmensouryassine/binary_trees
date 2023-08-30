#include "binary_trees.h"
#include <stdio.h>
#include <limits.h>

/**
 * min_max - determines the min(max) node in a tree
 * @tree:  is a pointer to the root node of the tree to check
 * @type: min (-1) or max (1)
 * Return: min (max)
 */
int min_max(const binary_tree_t *tree, int type)
{
	int n1, n2, res;

	if (type == -1)
		n1 = INT_MAX, n2 = INT_MAX;
	if (type == 1)
		n1 = INT_MIN, n2 = INT_MIN;

	if (tree->left == NULL && tree->right == NULL)
		return (tree->n);

	if (tree->left)
		n1 = min_max(tree->left, type);
	if (tree->right)
		n2 = min_max(tree->right, type);

	if (type == -1)
		res = n1 < n2 ? n1 : n2;
	if (type == 1)
		res = n1 > n2 ? n1 : n2;

	return (res);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (!tree)
		return (0);

	height_left = 1 + binary_tree_height(tree->left);
	height_right = 1 + binary_tree_height(tree->right);

	if (height_left >= height_right)
		return (height_left);
	else
		return (height_right);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid
 * Binary Search Tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int max = INT_MIN, min = INT_MAX;

	if (!tree)
		return (0);

	if (tree->left)
		max = min_max(tree->left, 1);
	if (tree->right)
		min = min_max(tree->right, -1);

	if (tree->n > max && tree->n < min)
		return (1);
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of
 * the tree to measure the balance factor
 * Return: The balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l, r, diff;

	if (!tree)
		return (0);

	l = binary_tree_height(tree->left);
	r = binary_tree_height(tree->right);

	diff = l > r ? l - r : r - l;
	if (diff > 1)
		return (0);
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_is_bst(tree) == 0)
		return (0);
	if (binary_tree_balance(tree) == 0
			|| binary_tree_balance(tree->left) == 0
			|| binary_tree_balance(tree->right) == 0)
		return (0);

	return (1);
}
