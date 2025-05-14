#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *node1, *node2, *temp;

    if (!list || !(*list))
      return;
    node2 = (*list)->next;
    while (node2)
    {
      node1 = node2;
      while (node1->prev != NULL && node1->prev->n > node1->n)
      {
        temp = node1->prev;
        /* start swap */
        if (temp->prev)
            temp->prev->next = node1;
        if (node1->next)
            node1->next->prev = temp;
        node1->prev = temp->prev;
        temp->next = node1->next;
        node1->next = temp;
        temp->prev = node1;
        if (temp == *list)
            *list = node1;
        print_list(*list);
        /* end swap */
      }
      node2 = node2->next;
    }
}
