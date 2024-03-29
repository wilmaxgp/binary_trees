#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, 0 otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (left_height > right_height)
        return (left_height + 1);
    else
        return (right_height + 1);
}

/**
 * binary_tree_nodes - Counts the nodes in a binary tree
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: The number of nodes in the tree, 0 otherwise
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height = 0;
    size_t nodes = 0;
    size_t max_nodes = 0;

    if (tree == NULL)
        return (0);

    height = binary_tree_height(tree);
    nodes = binary_tree_nodes(tree);
    max_nodes = (1 << height) - 1;

    return (nodes == max_nodes);
}
