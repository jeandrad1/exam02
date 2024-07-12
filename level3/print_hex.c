#include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    //skip the leading spaces and tabs
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    //if the number is negative, set the sign to -1 and increment i
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    //while the character is a digit
    while (str[i] >= '0' && str[i] <= '9')
    {
        //multiply the result by 10
        result = result * 10;
        //add the digit to the result
        result = result + str[i] - '0';
        i++;
    }
    //return the result
    return (result * sign);
}

void	print_hex(int n)
{
    //hexadecimal digits
	char hex_digits[] = "0123456789abcdef";

    //if the number above 16, call the function recursively
	if (n >= 16)
		print_hex(n / 16);
    //print the hexadecimal digit by taking the remainder of the number divided by 16
	write(1, &hex_digits[n % 16], 1);
}

int	main(int argc, char **argv)
{
    //if there is only one argument call the print_hex function with the argument 
    //converted to an integer
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}