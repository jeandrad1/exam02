#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr) 
{
    //man limits.h for min value of int
	if(nbr == -2147483648)
		return("-2147483648\0");
	int n = nbr;
	int len = 0;
    
    //if number is negative, add 1 to len
	if (nbr <= 0)
		len++;
    
    //count the number of digits
	while (n) 
	{
		n /= 10;
		len++;
	}
    
    //allocate memory for the string
	char *result = (char *)malloc(sizeof(char) * (len + 1));
    
    //malloc protection
	if (result == NULL) 
		return NULL;
    
    //close the string
	result[len] = '\0';

    //if number is 0, return 0
	if (nbr == 0)
	{
		result[0] = '0';
		return(result);
	}
        
    //if number is negative, add - to the string and make the number positive
	if (nbr < 0) 
	{
		result[0] = '-';
		nbr = -nbr;
	}
    //convert the number to string int to char (ich +)
	while (nbr) 
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return result;
}