#include <unistd.h>

int main(int argc, char **argv)
{
    if(argc == 3)
    {
        char *s1 = argv[1];
        char *s2 = argv[2];
        int i, j, k;

        // Process the first string
        i = 0;
        while(s1[i])
        {
            // Check for duplicate in s1
            j = 0;
            while(j < i)
            {
                if(s1[i] == s1[j])
                    break;
                j++;
            }
            // If no duplicate was found, j will be equal to i
            if(i == j)
                write(1, &s1[i], 1);
            i++;
        }

        // Process the second string
        i = 0;
        while(s2[i])
        {
            // Check for duplicate in s2
            j = 0;
            while(j < i)
            {
                if(s2[i] == s2[j])
                    break;
                j++;
            }
            // Check if s2[i] is in s1
            if(i == j)
            {
                k = 0;
                while(s1[k])
                {
                    if(s2[i] == s1[k])
                        break;
                    k++;
                }
                // If s2[i] was not found in s1, k will be at the end of s1
                if(!s1[k])
                    write(1, &s2[i], 1);
            }
            i++;
        }
    }
    // Write the final newline
    write(1, "\n", 1);
    return 0;
}