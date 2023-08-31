#include "binary_trees.h"

/**
 * free_queue - free a queue
 * @head: a pointer to the head of the queue
 */
void free_queue(binary_tree_queue_t *head)
{
	binary_tree_queue_t *curr;

	while (head)
	{
		curr = head->next;
		free(head);
		head = curr;
	}
}

/**
 * push_queue - insert a node in a queue
 * @node: a pointer to the node to be created
 * @tail: a pointer to the tail of queue
 * @head: a pointer to the head of queue
 */
void push_queue(binary_tree_t *node, binary_tree_queue_t **tail,
		binary_tree_queue_t *head)
{
	binary_tree_queue_t *new;

	new = malloc(sizeof(binary_tree_queue_t));
	if (!new)
	{
		free_queue(head);
		exit(1);
	}

	new->node = node;
	new->next = NULL;

	(*tail)->next = new;
	*tail = new;
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if binary tree is complete, 0 otherwize
 */
int is_complete(const binary_tree_t *tree)
{
	binary_tree_queue_t *head, *tail, *curr;
	int not_exist = 0;

	if (!tree)
		return (0);
	head = malloc(sizeof(binary_tree_queue_t));
	if (!head)
		exit(1);
	head->node = (binary_tree_t *)tree;
	head->next = NULL;
	tail = head;
	while (head)
	{
		if (head->node->left)
		{
			if (not_exist)
			{
				free_queue(head);
				return (0);
			}
			push_queue(head->node->left, &tail, head);
		}
		else
			not_exist = 1;
		if (head->node->right)
		{
			if (not_exist)
			{
				free_queue(head);
				return (0);
			}
			push_queue(head->node->right, &tail, head);
		}
		else
			not_exist = 1;
		if (head)
			curr = head->next, free(head), head = curr;
	}
	return (1);
}

/**
 * is_max - check if a binary tree is a max binary heap
 * @tree: a pointer to the tree to check
 * Return: 1 if it's a max binary tree, 0 otherwise
 */
int is_max(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left && tree->n < tree->left->n)
		return (0);

	if (tree->right && tree->n < tree->right->n)
		return (0);

	return (is_max(tree->left) && is_max(tree->right));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_complete(tree))
		return (0);

	if (!is_max(tree))
		return (0);

	return (1);
}
