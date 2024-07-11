#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

    //tmp is a copy of the list at the beginning
	tmp = lst;

    //loop through the list
	while(lst->next != NULL)
	{
        //if the current element is greater than the next element
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
            //swap the elements
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
            //start from the beginning of the list using tmp
			lst = tmp;
		}
        //if the current element is less than the next element it keeps going
		else
			lst = lst->next;
	}
    //puts the list back to the beginning
	lst = tmp;
    //returns the sorted list
	return (lst);
}