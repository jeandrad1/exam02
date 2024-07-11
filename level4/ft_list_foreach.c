typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

//#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    //while the list is not empty
    while (begin_list)
    {
        //apply the function to the data
        (*f)(begin_list->data);
        //move to the next element
        begin_list = begin_list->next;
    }
}
