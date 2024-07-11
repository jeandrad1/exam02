#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    //if the list is empty, return
	if (begin_list == NULL || *begin_list == NULL)
		return;

    //create a pointer to the first element
	t_list *cur = *begin_list;

    //if the data is equal to the reference data
	if (cmp(cur->data, data_ref) == 0)
	{
        //move the pointer to the next element
		*begin_list = cur->next;

        //free the current element
		free(cur);

        //recursively call the function
		ft_list_remove_if(begin_list, data_ref, cmp);
	}

    //if the data is not equal to the reference data
    //recursively call the function
	else // if there is a no else, you cant pass the Moulinette, tryed 2023.09.08
	{
		cur = *begin_list;
		ft_list_remove_if(&cur->next, data_ref, cmp);
	}
}