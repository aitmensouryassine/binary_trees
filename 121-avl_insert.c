#include "binary_trees.h"
#include <stdio.h>

/**
 * avl_insert_rec - inserts a value in a Binary Search Tree
 * @tree: is a double pointer to the root node of the BST
 * to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the created node or NULL
 */
avl_t *avl_insert_rec(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		if (!new)
			return (NULL);

		*tree = new;
		return (new);
	}

	if ((*tree)->n > value)
	{
		if ((*tree)->left != NULL)
			return (avl_insert_rec(&((*tree)->left), value));

		new = binary_tree_node(*tree, value);
		if (!new)
			return (NULL);
		(*tree)->left = new;

		return (new);
	}
	else if ((*tree)->n < value)
	{
		if ((*tree)->right != NULL)
			return (avl_insert_rec(&((*tree)->right), value));

		new = binary_tree_node(*tree, value);
		if (!new)
			return (NULL);
		(*tree)->right = new;

		return (new);
	}
	else
		return (*tree);
}

/**
 * check_imbalance - check for imbalanced node starting from node and up
 * @node: a pointer to the node from which to start looking for the
 * imbalanced node
 * Return: a pointer to the imbalanced node or NULL on failure
 */
binary_tree_t *check_imbalance(binary_tree_t *node)
{
	int balance_factor;

	if (!node)
		return (NULL);

	balance_factor = binary_tree_balance(node);
	if (balance_factor < -1 || balance_factor > 1)
		return (node);

	return (check_imbalance(node->parent));
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
	avl_t *new, *imbalance_node;
	int balance_factor;

	if (!tree || !value)
		return (NULL);

	new = avl_insert_rec(tree, value);
	if (!new)
		return (NULL);

	imbalance_node = check_imbalance(new->parent);
	if (imbalance_node)
	{
		balance_factor = binary_tree_balance(imbalance_node);
		if (balance_factor >= 2)
		{
			/* printf("balance %d LL or LR\n", balance_factor); */
			if (imbalance_node->left->n < value)
			{
				binary_tree_rotate_left(imbalance_node->left);
				binary_tree_rotate_right(imbalance_node);
			}
			else if (imbalance_node->left->n > value)
				binary_tree_rotate_right(imbalance_node);
		}
		else
		{
			/* printf("balance %d RR or RL\n", balance_factor); */
			if (imbalance_node->right->n > value)
			{
				binary_tree_rotate_right(imbalance_node->right);
				binary_tree_rotate_left(imbalance_node);
			}
			else if (imbalance_node->right->n < value)
				binary_tree_rotate_left(imbalance_node);
		}
	}
	return (new);
}
