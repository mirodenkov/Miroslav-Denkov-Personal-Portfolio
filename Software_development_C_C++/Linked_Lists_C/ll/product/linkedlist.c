/* SD exercise 1: simple linked list API */
/* Author : R. Frenken                   */
/* Version : 1.0			 */
#include "linkedlist.h"
#include <stdlib.h>

/***************************************************/
/* If *list == NULL, a new list should be created, */
/* otherwise prepend a new ITEM with value value   */
/* to the existing list                            */
/* Returns -1 if not enough memory, otherwise 0    */
/***************************************************/

int add_first(ITEM **list, int value)
{
	ITEM *new_node = (ITEM *)malloc(sizeof(ITEM));
	if (new_node == NULL) // memory fails
	{
		return -1;
	}
	new_node->value = value;
	new_node->next = *list;

	*list = new_node;

	return 0;
}

/***************************************************/
/* If *list == NULL, a new list should be created, */
/* otherwise append a new ITEM with value value to */
/* the existing list                               */
/* Returns -1 if not enough memory, otherwise 0    */
/***************************************************/

int add_last(ITEM **list, int value)
{

	if (*list == NULL)
	{
		ITEM *new_node = (ITEM *)malloc(sizeof(ITEM));
		if (new_node == NULL)
		{
			return -1; // memory allocation failed
		}
		new_node->value = value;
		*list = new_node;
		return 0;
	}

	ITEM *current_node = *list; //*list is a pointer to the first node
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}

	ITEM *new_node = (ITEM *)malloc(sizeof(ITEM));
	if (new_node == NULL)
	{
		return -1;
	}

	new_node->value = value;
	new_node->next = NULL;
	current_node->next = new_node;

	return 0;
}

/****************************************************/
/* Insert a new item after current item c_item      */
/* Returns -1 if not enough memory, c_item == NULL, */
/* *list == NULL or c_item not found, otherwise 0   */
/****************************************************/

int add_after(ITEM *list, ITEM *c_item, int value)
{
	if (list == NULL || c_item == NULL) 
	{
		return -1;
	}

	// Traverse the list to find c_item
	ITEM *current_node = list;
	while (current_node != NULL)
	{
		if (current_node == c_item) 
		{
			
			ITEM *new_node = (ITEM *)malloc(sizeof(ITEM));
			if (new_node == NULL)
			{
				return -1;
			}

			new_node->value = value;
			new_node->next = current_node->next; 
			current_node->next = new_node;		 

			return 0; 
		}

		current_node = current_node->next; 
	}

	return -1;  
}

/***************************************************/
/* Remove first item of the list                   */
/* Returns -1 if list==NULL, otherwise 0           */
/***************************************************/

int rem_first(ITEM **list)
{
	if (*list == NULL)
	{
		return -1; 
	}

	ITEM *temp = *list;	   
	*list = (*list)->next; 

	free(temp); 

	return 0; 
}

/***************************************************/
/* Remove last item of the list                    */
/* Returns -1 if list==NULL, otherwise 0           */
/***************************************************/

int rem_last(ITEM **list)
{
    // Check if list is empty
    if (*list == NULL)
    {
        return -1;
    }

    
    if ((*list)->next == NULL)
    {
        free(*list);
        *list = NULL;
        return 0;
    }

    // Traverse to the second-last node
    ITEM *current = *list;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

  
    free(current->next);
    current->next = NULL;

    return 0;
}

/***************************************************/
/* Remove item after c_item of the list            */
/* Returns -1 list==NULL, c_item not found or      */
/* c_item is the last_element                      */
/***************************************************/

int rem_after(ITEM *list, ITEM *c_item)
{
    
    if (list == NULL || c_item == NULL || c_item->next == NULL)
    {
        return -1; 
    }

    ITEM *to_remove = c_item->next; 
    c_item->next = to_remove->next; 
    free(to_remove); 

    return 0; 
}


/*********************************************************/
/* All dynamic memory allocated to the list is freed     */
/* Empty list should point to NULL                       */
/*********************************************************/

void clean(ITEM **list)
{
    ITEM *current = *list;
    while (current != NULL) {
        ITEM *next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}
