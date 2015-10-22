    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    #define SIZE 65535
     
    int main(int argc, char *argv[])
    {
     
	    char buffer[SIZE];
	    unsigned long n, k, input, count;
	    int c, i;
	    count = 0;
	     
	    scanf("%lu %lu\n", &n, &k);
	    input = 0;
     
	    while ((c = fread (buffer, sizeof (char), SIZE, stdin)) > 0)
	    {
		    for (i = 0; i < c; i++)
		    {
			    if (buffer[i] == '\n')
			    {
				    if ((input % k) == 0) {
				    count++;
			    }
			    input = 0;
			    }
			    else
			    {
			    	input = (input * 10) + (buffer[i] - '0');
			    }
			}
		     
		    }
	     
	    printf("%lu\n", count);
	    return 0;
    } 