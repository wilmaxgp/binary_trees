#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *temp1 = first, *temp2 = second;

    if (first == NULL || second == NULL)
        return (NULL);

    while (temp1 != temp2)
    {
        temp1 = (temp1 != NULL) ? temp1->parent : second;
        temp2 = (temp2 != NULL) ? temp2->parent : first;
    }

    return ((binary_tree_t *)temp1);
}
