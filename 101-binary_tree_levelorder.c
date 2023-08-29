#include "binary_trees.h"

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

	if (tree->left)
		height_left = 1 + binary_tree_height(tree->left);
	else
		height_left = 0;

	if (tree->right)
		height_right = 1 + binary_tree_height(tree->right);
	else
		height_right = 0;

	if (height_left >= height_right)
		return (height_left);
	else
		return (height_right);
}

/**
 * print_level - prints a level
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * @level: the level to print
 */
void print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 0)
	{
		func(tree->n);
		return;
	}

	print_level(tree->left, func, level - 1);
	print_level(tree->right, func, level - 1);
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	level = 0;

	for (level = 0; level <= height; level++)
		print_level(tree, func, level);
}
