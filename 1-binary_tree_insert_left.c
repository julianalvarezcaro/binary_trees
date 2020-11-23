#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left_child of another
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;


	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->right = NULL;

	/*
	* If the parent already had a left-child, new node will take its place
	* and the former left-child will now be the left-child of the new node.
	*/
	node->left = parent->left;
	if (parent->left != NULL)
	{
		parent->left->parent = node;
	}
	parent->left = node;
	return (node);
}
