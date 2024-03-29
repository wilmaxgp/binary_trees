#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    const binary_tree_t **queue;
    int front = 0, rear = 0;
    int capacity = 10;

    if (tree == NULL || func == NULL)
        return;

    queue = malloc(sizeof(binary_tree_t *) * capacity);
    if (queue == NULL)
        return;

    queue[rear++] = tree;

    while (front != rear)
    {
        const binary_tree_t *current = queue[front++];

        func(current->n);

        if (current->left != NULL)
        {
            if (rear >= capacity)
            {
                capacity *= 2;
                queue = realloc(queue, sizeof(binary_tree_t *) * capacity);
                if (queue == NULL)
                    return;
            }
            queue[rear++] = current->left;
        }

        if (current->right != NULL)
        {
            if (rear >= capacity)
            {
                capacity *= 2;
                queue = realloc(queue, sizeof(binary_tree_t *) * capacity);
                if (queue == NULL)
                    return;
            }
            queue[rear++] = current->right;
        }
    }

    free(queue);
}
