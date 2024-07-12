typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                t_list;

int	ft_list_size(t_list *begin_list)
{
    int i = 0;
    //if the list is empty, return 0
	if (begin_list == 0)
		return (0);
    //else increment i while the list is not empty
	else
        {
            while (begin_list)
            {
                i++;
                //move to the next element
                begin_list = begin_list->next;
            }
        }
        //return the number of elements in the list
		return (i);
}

void put_nbr(int n)
{
    if(n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }

    if (n < 0)
    {
        n = -n;
        write(1, "-", 1);
    }
    
    if (n < 10)
    {
        n = n + '0';
        write(1, &n, 1);
    }
    else
    {
        put_nbr(n / 10);
        put_nbr(n % 10);
    }
}

int main(int argc, char **argv)
{
    (void) argv;
    put_nbr(argc);
    return 0;
}