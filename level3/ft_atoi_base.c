#include <stdio.h>
//function that transforms an uppercase char to a lowercase string
char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

//function that returns the digit of a character in a given base
int get_digit(char c, int digits_in_base)
{
	int max_digit;
    //if the base is less than or equal to 10, the max digit is the base + '0'
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	//else the max digit is the base + 'a'
    else
		max_digit = digits_in_base - 10 + 'a';
    
    //if the character is a digit and is less than or equal to the max digit
    //return the digit
	if (c >= '0' && c <= '9' && c <= max_digit)
    //return the digit
    		return (c - '0');
    //if the character is a letter and is less than or equal to the max digit
    else if (c >= 'a' && c <= 'f' && c <= max_digit)
	//return the digit
    	return (10 + c - 'a');
	else
    //return -1
		return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;
    int i = 0;

    //if str is negative, set the sign to -1 and increment str
 	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

    //if str starts with 0x or 0X, increment str by 2
	while ((digit = get_digit(to_lower(str[i]), str_base)) >= 0)
	{
        //multiply the result by the base
		result = result * str_base;
        //add the digit to the result
		result = result + (digit * sign);
        //increment str
		i++;
	}
    //return the result
	return (result);
}

int main()
{
    printf("%d\n", ft_atoi_base("123", 10));
    printf("%d\n", ft_atoi_base("123", 16));
    printf("%d\n", ft_atoi_base("123", 2));
    printf("%d\n", ft_atoi_base("123", 8));
}
