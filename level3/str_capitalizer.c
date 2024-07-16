#include <unistd.h>


int	is_lower(char c)
{
	if(c >= 'a' && c <= 'z')
		return 1;
	else
		return 0;
}

int	is_upper(char c)
{
	if(c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}

void  str_cap(char *str)
{
	int i = 0;

	//put all in upper in lower
	while(str[i])
	{
		if(is_upper(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	
	i = 0;
	//skips all intial spaces again
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	
	//put the first char in upper
	if(is_lower(str[i]))
                str[i] = str[i] - 32;
        i++;

	//put all the first chars of words in upper
	while(str[i])
	{
		if(is_lower(str[i]) && (str[i - 1] == ' ' || str[i - 1] == '\t'))
                	str[i] = str[i] - 32;
        	i++;
	}

	//write the whole prhase 
	i = 0;
	while(str[i])
	{
		write(1,&str[i],1);
		i++;
	}

}

int main(int argc, char **argv)
{
	if(argc < 2)
		write(1,"\n",1);
	else
	{

		int i = 1;
		while(i < argc)
		{
			str_cap(argv[i]);
			write(1,"\n",1);
			i++;
		}
	}
	return (0);
}
