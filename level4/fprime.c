#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	number;

	if (argc == 2)
	{
		i = 1;

		//atoi to put the argument into a integer
		number = atoi(argv[1]);
		if (number == 1)
			printf("1");
        //Euclid Algorithm to find the 
		//prime factors of a number and print them
		while (number >= i)
		{
			if (number % i == 0)
			{
				printf("%d", i);
                if (number == i)
					break ;
				printf("*");
				number /= i;
				i = 1;
			}
            i++;
		}
	}
	printf("\n");
	return (0);
}
