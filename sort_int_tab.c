#include <stdio.h>
#include <stdlib.h>

//sorts an array of integers in ascending order
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

    // loop through the array
	while (i < (size - 1))
	{
        // if the current element is greater than the next element
		if (tab[i] > tab[i + 1])
		{
            // swap the elements
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
            // start from the beginning of the array
			i = 0;
		}
        // if the current element is less than the next element it keeps going
		else
			i++;
	}
}

//main to test the function
int main(int argc, char **argv)
{
    int	tab[argc - 1];
    int	i = 1;

    if (argc < 1)
        return (0);
    
    while (i < argc)
    {
        tab[i - 1] = atoi(argv[i]);
        i++;
    }
    sort_int_tab(tab, argc - 1);
    i = 0;
    while (i < argc - 1)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    return (0);
}