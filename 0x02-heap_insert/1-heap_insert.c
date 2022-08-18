#include "binary_trees.h"

/**
 * heap_insert - Deallocate a binary tree
 * @root: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: return the new node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	if (*root == NULL)
		return (binary_tree_node(*root, value));

	binary_tree_inorder(*root, value, &binary_insert_left);
}

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: tree to traverse
 * @func: function to print
 */

void binary_tree_inorder(const heap_t *tree, int value, heap_t (*func)(int))
{
	if (tree == NULL || func == NULL || tree->n < value)
		return;
	binary_tree_inorder(tree->left, func);
	if (tree->n > value)
		func(value);
	binary_tree_inorder(tree->right, func);
}

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *tempNode;

	if (!parent)
		return (NULL);
	tempNode = binary_tree_node(parent, value);
	if (tempNode == NULL)
		return (NULL);
	tempNode->left = parent->left;
	parent->left = tempNode;
	if (tempNode->left)
		tempNode->left->parent = tempNode;
	return (tempNode);
}
