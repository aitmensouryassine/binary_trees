#include "binary_trees.h"

/**
 * create_queue_node - create a queue node
 * @node: the node to be created
 * Return: a pointer to a creted node or NULL
 */
binary_tree_queue_t *create_queue_node(binary_tree_t *node)
{
	binary_tree_queue_t *new;

	new = malloc(sizeof(binary_tree_queue_t));
	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;
	return (new);
}

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

	new = create_queue_node(node);
	if (!new)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop_queue_head - remove the head of the queue
 * @head: a pointer to the head of the queue
 */
void pop_queue_head(binary_tree_queue_t **head)
{
	binary_tree_queue_t *curr;

	if (head)
	{
		curr = (*head)->next;
		free(*head);
		*head = curr;
	}
}


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if binary tree is complete, 0 otherwize
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_queue_t *head, *tail;
	int not_exist = 0;

	if (!tree)
		return (0);

	head = tail = create_queue_node((binary_tree_t *)tree);
	if (!head)
		exit(1);

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

		pop_queue_head(&head);
	}

	return (1);
}
