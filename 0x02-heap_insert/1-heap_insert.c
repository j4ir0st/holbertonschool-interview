#include "binary_trees.h"

/**
 * heap_insert - Deallocate a binary tree
 * @root: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: return the new node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_inorder(*root, value, &binary_tree_node);
}

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @tree: tree to traverse
 * @func: function to print
 */

void binary_tree_inorder(const heap_t *tree, int value, heap_t (*func)(int))
{
	if (tree == NULL || func == NULL || tree->n > value)
		return;
	binary_tree_inorder(tree->left, func);
	if (tree->n > value)
		func(value);
	binary_tree_inorder(tree->right, func);
}

/**
 * binary_tree_node - Deallocate a binary tree
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 * Return: return the new node
 */

heap_t *binary_tree_node(heap_t *parent, int value)
{
        heap_t *new;

        new = malloc(sizeof(binary_tree_t));
        if (new == NULL)
                return (NULL);
        new->n = value;
        new->parent = parent;
        new->left = NULL;
        new->right = NULL;
        parent = new;
        return (new);
}
