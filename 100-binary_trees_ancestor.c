#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * of two nodes
 * @first: is a pointer to the first node
 * @second:  is a pointer to the second node
 * Return: the lowest common ancestor or NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (first == second->parent)
		return ((binary_tree_t *)first);

	if (second == first->parent)
		return ((binary_tree_t *)second);

	return (binary_trees_ancestor(first->parent, second->parent));
}
