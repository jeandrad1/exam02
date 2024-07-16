#include <unistd.h>

void write_word(int i,int j,  char *str)
{
    while (i < j)
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    char *str;
    int first_word_start;
    int first_word_end;
    int i = 0;

    // check if there is at least one argument
    if (argc > 1)
    {
        //cast the first argument to a char pointer
        str = argv[1];
        
        //skip the leading spaces and tabs
        while (str[i] == ' ' || str[i] == '\t') 
            i++;
        
        // set the start of the first word
        first_word_start = i;

        // move to the end of the first word
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;

        // set the end of the first word
        first_word_end = i;

        // move to the next word
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        
        // check if there is a next word and write all the next words as requested
        if (str[i])
        {
            // write the next word
            while (str[i])
            {
                // skip the spaces and tabs and only write one space
                if (str[i] == ' ' || str[i] == '\t')
                {
                    while (str[i] == ' ' || str[i] == '\t')
                        i++;
                    if (str[i])
                        write(1, " ", 1);
                } 
                // write the word
                else 
                {
                    write(1, &str[i], 1);
                    i++;
                }
            }
            //write one space at the end
            write(1, " ", 1);
        }
        // write the first word
        write_word(first_word_start,first_word_end ,str);
    }
    //write a new line
    write(1, "\n", 1);
    return 0;
}