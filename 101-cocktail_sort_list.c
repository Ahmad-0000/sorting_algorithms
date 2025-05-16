#include "sort.h"
#define TRUE 1
#define FALSE 0

void cocktail_sort_list(listint_t **list)
{
    listint_t *traveler, *temp, *last;
    int swapped = TRUE;

    if (list == NULL || *list == NULL)
      return;
    do {
      traveler = *list;
      while (traveler)
      {
        if (traveler->next && (traveler->n > traveler->next->n))
        {
          temp = traveler->next;
          if (traveler->prev)
            traveler->prev->next = temp;
          if (temp->next)
            temp->next->prev = traveler;
          traveler->next = temp->next;
          temp->prev = traveler->prev;
          traveler->prev = temp;
          temp->next = traveler;
          if (*list == traveler)
            *list = temp;
          swapped = TRUE;
          print_list(*list);
          if (traveler->next == NULL)
            last = traveler;
          continue;
        }
          if (traveler->next == NULL)
            last = traveler;
        traveler = traveler->next;
      }
      if (swapped == FALSE)
        break;
      swapped = FALSE;
      while (last)
      {
        if (last->prev && (last->n < last->prev->n))
        {
          temp = last->prev;
          if (temp->prev)
            temp->prev->next = last;
          if (last->next)
            last->next->prev = temp;
          temp->next = last->next;
          last->prev = temp->prev;
          temp->prev = last;
          last->next = temp;
          if (*list == temp)
            *list = last;
          swapped = TRUE;
          print_list(*list);
          continue;
        }
        last = last->prev;
      }
    } while (swapped);
}
