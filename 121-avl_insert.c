#include "binary_trees.h"

/**
 * avl_insert_rec - inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST
 * to insert the value
 * @value: is the value to store in the node to be inserted
 * @parent: the parent of the node
 * @node: a pointer to the created node
 * Return: a pointer to the created node or NULL
 */

avl_t *avl_insert_rec(avl_t *tree, avl_t *parent, int value, avl_t **node)
{
	int balance;

	if (!tree)
	{
		*node = binary_tree_node(parent, value);
		if (*node == NULL)
			return (NULL);
		return (*node);
	}

	if (value < tree->n)
	{
		tree->left = avl_insert_rec(tree->left, tree, value, node);
		if (tree->left == NULL)
			return (NULL);
	}
	else if (value > tree->n)
	{
		tree->right = avl_insert_rec(tree->right, tree, value, node);
		if (tree->right == NULL)
			return (NULL);
	}
	else
		return (tree);

	balance = binary_tree_balance(tree);

	if (balance > 1 && value < tree->left->n)
		tree = binary_tree_rotate_right(tree);

	if (balance < -1 && value > tree->right->n)
		tree = binary_tree_rotate_left(tree);

	if (balance > 1 && value > tree->left->n)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		tree = binary_tree_rotate_right(tree);
	}

	if (balance < -1 && value < tree->right->n)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		tree = binary_tree_rotate_left(tree);
	}

	return (tree);
}


/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: a double pointer to the root node of the AVL tree for
 * inserting the value
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new;

	if (!tree || !value)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		if (*tree == NULL)
			return (NULL);
		return (*tree);
	}
	avl_insert_rec(*tree, *tree, value, &new);
	return (new);
}
