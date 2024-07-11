#include <unistd.h>

//converts a string to an integer
int	ft_atoi(char *s)
{
	int	res = 0;
    int i = 0;

	while (s[i])
    {
        res = res * 10;
        res += s[i] - '0';
        i++;
    }
	    return (res);
}

//checks if a integer number is prime
int	is_prime(int num)
{
	int	i = 2;

	if (num <= 1)
		return (0);
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

//prints a number
//does not handle negative numbers
void	put_nbr(int n)
{
	if (n >= 10)
		put_nbr(n / 10);
	char digit = n % 10 + '0';
	write(1, &digit, 1);
}

//main function
int main(int ac, char **av)
{
    //if there is only one argument
	if (ac == 2)
	{
        //convert the argument to an integer
		int	nbr = ft_atoi(av[1]);
        //initialize the sum
		int	sum = 0;

        //decrement the number and add the prime numbers to the sum
		while (nbr > 0)
		{
            //if the number is prime increment the sum by the number
			if (is_prime(nbr))
				sum += nbr;

            //decrement the number
			nbr--;
		}
        //print the sum
		put_nbr(sum);
	}

    //if there are no arguments print 0
    
    else
	if (ac != 2)
		put_nbr(0);

    //print a new line
	write(1, "\n", 1);
	return (0);
}