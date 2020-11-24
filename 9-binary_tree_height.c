#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
		return (0);
	aux_height(tree, 0, &height);
	return (height);
}

/**
 * aux_height - recursively gets the height of each node and sets
 *
 * @tree: tree to get heights from
 * @node_h: height of the current node
 * @height: pointer to the variable that contains the max height so far
 *
 * Return: void
 */
void aux_height(const binary_tree_t *tree, size_t node_h, size_t *height)
{
	if (tree->left)
		aux_height(tree->left, node_h + 1, height);
	if (tree->right)
		aux_height(tree->right, node_h + 1, height);
	if (is_leaf(tree) && node_h > *height)
		*height = node_h;
}

/**
 * is_leaf - checks if a node is a leaf
 *
 * @node: node to be checked
 *
 * Return: 1 if node is a leaf. 0 otherwise or in case of error
 */
int is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
