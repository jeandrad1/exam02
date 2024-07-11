#include <unistd.h>

int main(int argc, char const *argv[])
{
    int i;
    int flag = 0;

    //if there is only one argument
    if (argc == 2)
    {
        i = 0;
        //skip the leading spaces and tabs
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        //iterate through the string
        while (argv[1][i])
        {
            //if the character is a space or a tab set the flag
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1;
            //if the character is not a space or a tab
            else
            {
                //if the flag is set print a space
                if (flag)
                    write(1, "   ", 3);
                //reset the flag
                flag = 0;
                //print the character
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    //print a newline
    write(1, "\n", 1);
    return (0);
}