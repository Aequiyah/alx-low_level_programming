#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head = NULL;
    dlistint_t *ptr;
    int ints[] = {0, 1, 2, 3, 4, 98, 402, 1024};
    size_t i, n;

    for (i = 0; i < sizeof(ints) / sizeof(ints[0]); i++)
    {
        ptr = add_dnodeint(&head, ints[i]);
        if (ptr == NULL)
        {
            fprintf(stderr, "Failed to add node\n");
            return EXIT_FAILURE;
        }
    }

    n = print_dlistint(head);
    printf("-> %lu elements\n", n);

    return EXIT_SUCCESS;
}

