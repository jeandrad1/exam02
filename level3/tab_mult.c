#include <unistd.h>
#include <stdio.h>

//atoi to put the argument into a integer
int	ft_atoi(char *s)
{
	int i = 0;
	int sng = 1;
	int n = 0;

	while(s[i] == ' ' || s[i] == '\t')
		i++;
	
	if(s[i] == '+')
		i++;
	
	if(s[i] == '-')
	{
		sng = -sng;
		i++;
	}

	while(s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return(n * sng);
}

//putnbr to print the number
void	ft_putnbr(int n)
{
	char c = 0;
	if(n < 10)
	{
		c = n + '0';
		write(1,&c,1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr( n % 10);
	}
}

//putstr to print the string
void	ft_putstr(char *s)
{
	int i = 0;
	while(s[i])
	{
		write(1,&s[i],1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		//cast the argument to a string for easier use and initialize the number i to 1
		char *s = argv[1];
		int i = 1;

		//convert the string to a integer
		int num = ft_atoi(s);

		//initialize the result as 0 for now
		int res = 0;
		while (i < 10)
		{
			//print the multiplication table by first printing the number, then the multiplication sign,
			//then the number to multiply by, then the equal sign, then the result
			ft_putnbr(i);
			write(1," x ",3);
			ft_putstr(s);
			write(1," = ",3);
			res = i * num;
			ft_putnbr(res);
			write(1,"\n",1);
			i++;
		}
	}
	else
		write(1,"\n",1);
	return (0);
}
