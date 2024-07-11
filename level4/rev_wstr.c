#include <unistd.h>

int main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
		
	if(argc == 2)
	{
        //find the end of the string   
		while(argv[1][i] != '\0')
			i++;
		while(i >= 0)
		{
            //skip the spaces
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
            
            //find the end of the word
			end = i;

            //find the start of the word
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
            
            //set the start of the word
			start = i + 1;

            //flag to print space
			int  flag;
			flag = start;

            //print the word
			    while(start <= end)
			    {
				    write (1, &argv[1][start],1);
				    start++;		
			    }

            //print space
			if (flag !=0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}