#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as a right-child of another
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;

	/*
	* If the parent already had a right-child, new node will take its place
	* and the former right-child will now be the right-child of the new node.
	*/
	node->right = parent->right;
	if (parent->right != NULL)
	{
		parent->right->parent = node;
	}
	parent->right = node;
	return (node);
}
