#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree; // Return root if tree is empty
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
        if ((*tree)->left == NULL)
            return NULL; // Allocation failure
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
        if ((*tree)->right == NULL)
            return NULL; // Allocation failure
    }
    else
    {
        // Handle duplicate values according to your strategy
        // For example, you may choose to disallow duplicates
        // return NULL;
    }

    // Re-balance the tree after insertion
    binary_tree_balance(*tree
