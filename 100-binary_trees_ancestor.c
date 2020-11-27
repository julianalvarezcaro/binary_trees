#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest ancestor. NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t **f_pointers, **s_pointers;
	binary_tree_t *f_nodes, *s_nodes, *root;
	int h, pos_f, pos_s;

	if (first == NULL || second == NULL)
		return (NULL);
	root = first->parent;
	while (root->parent)
		root = root->parent;
	h = height(root);
	f_pointers = malloc(sizeof(binary_tree_t *) * h);
	s_pointers = malloc(sizeof(binary_tree_t *) * h);
	f_nodes = first->parent;
	pos_f = 0;
	while (f_nodes)
	{
		f_pointers[pos_f] = f_nodes;
		f_nodes = f_nodes->parent, pos_f++;
	}
	s_nodes = second->parent;
	pos_s = 0;
	while (s_nodes)
	{
		s_pointers[pos_s] = s_nodes;
		s_nodes = s_nodes->parent, pos_s++;
	}
	f_nodes = f_pointers[0], s_nodes = s_pointers[0];
	for (pos_s = 0; s_nodes; pos_s++)
	{
		s_nodes = s_pointers[pos_s];
		for (pos_f = 0; f_nodes; pos_f++)
		{
			f_nodes = f_pointers[pos_f];
			if (s_nodes == f_nodes || s_nodes == first ||
			f_nodes == second)
				return (s_nodes);
		}
		f_nodes = f_pointers[0];
	}
	return (s_nodes);
}

/**
 * height - gets the height of a tree
 *
 * @tree: tree to get the height from
 *
 * Return: height of the tree
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);
	else
		return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * max - get the max number between two
 *
 * @a: int
 * @b: int
 *
 * Return: ax between a and b
 */
int max(int a, int b)
{
	return ((a >= b) ? a : b);
}
