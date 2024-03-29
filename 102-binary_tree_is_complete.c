#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    size_t size, i;
    const binary_tree_t **queue;

    if (tree == NULL)
        return (0);

    size = binary_tree_size(tree);
    queue = malloc(sizeof(binary_tree_t *) * size);
    if (queue == NULL)
        return (0);

    queue[0] = tree;
    for (i = 0; i < size; i++)
    {
        const binary_tree_t *current = queue[i];

        if (current == NULL)
            break;

        queue[2 * i + 1] = current->left;
        queue[2 * i + 2] = current->right;
    }

    for (; i < size; i++)
    {
        if (queue[i] != NULL)
        {
            free(queue);
            return (0);
        }
    }

    free(queue);
    return (1);
}
