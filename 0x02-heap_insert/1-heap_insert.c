#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another \
node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: a pointer to the new node, or NULL on failure
 */

heap_t *binary_tree_insert_left(heap_t *parent, int value)
{
        heap_t *tempNode;

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

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: tree to traverse
 * @func: function to print
 */

heap_t *binary_tree_inorder(heap_t *tree, int value)
{
	heap_t *left = NULL, *right = NULL;

	if (tree == NULL || tree->n < value)
		return (NULL);
	left = binary_tree_inorder(tree->left, value);
	if (left)
		return (binary_tree_insert_left(left, value));
	right = binary_tree_inorder(tree->right, value);
	if (right)
                return (binary_tree_insert_left(right, value));
	return (tree);
}

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

        return (binary_tree_inorder(*root, value));
}
