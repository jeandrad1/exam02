#include <unistd.h>
#include <stdio.h>
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
		char *s = argv[1];
		int i = 1;
		int num = ft_atoi(s);
		int res = 0;
		while (i < 10)
		{
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
