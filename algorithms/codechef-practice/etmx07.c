#include <stdio.h>
#include <stdlib.h>

void printMirroredString (char * s)
{
	int len = 0, i = 0;
	
	while (s[i++])
		len++;
	
	i = 0;	
	while (s[i])
	{
		if (s[i] == s[len - i - 1])
		{
			printf ("%c", s[i]);
			i++;
		}
		else
			break;
	}		
	printf ("\n");
}

int main (void)
{
	unsigned int len_max = 128;
    unsigned int current_size = 0;
 
    char * pStr = malloc (len_max);
    current_size = len_max;
 
    if (pStr != NULL)
    {
		int c = EOF;
		unsigned int i = 0;
        
        //accept user input until hit enter or end of file
        
        while (( c = getchar() ) != '\n' && c != EOF)
		{
			pStr[i++] = (char) c;
 
			//if i reached maximize size then realloc size
			if (i == current_size)
			{
				current_size = i + len_max;
				pStr = realloc (pStr, current_size);
			}
		}
 
		pStr[i] = '\0';
 
		printMirroredString (pStr);
		
        free(pStr);
        pStr = NULL;
    }
	return 0;
}
