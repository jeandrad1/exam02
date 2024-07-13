#include <stdlib.h>
#include <stdio.h>

//ft_strncpy to copy n bytes from s2 to s1
char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (i < n && s2[i])
    {
		s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
	return (s1);
}
int	ft_count_words(char *str)
{
	int i = 0;
	int wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	return(wc)
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;
	
    //allocate memory for the array of strings
	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	
    //split the string into words
	while (str[i])
	{
		int wc = ft_count_words(str);
        //skip the spaces and find the start of the word
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;

        //find the end of the word
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
        
        //allocate memory for the word and copy it
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}

    //set the last element of the array to NULL
	out[k] = NULL;
	return (out);
}