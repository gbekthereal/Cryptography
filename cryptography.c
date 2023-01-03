#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char mapcharacter(char c, int dist)
{
	if (islower(c))
		/* (c - 'a') is the position of letter c in the alphabet (a is 0, b is 1, ...) 
		 * (n + dist) % 26, gives the number dist positions after n (circularly).
		 */
		return ( 'a' + (((c-'a') + dist + 26) % 26) );
	else
		if (isupper(c))
			return ( 'A' + (((c-'A') + dist + 26) % 26) );
		else
			return (c);
}


char *encrypt(char *str, int dist)
{
	char *new, *t;
	
	new = (char *) malloc(strlen(str) + 1);
	if (new == NULL) 
	  exit(1);
	for (t = new; *str != '\0'; str++, t++)
		*t = mapcharacter(*str, dist);
	*t = '\0';
	return (new);
}


void decrypt(char *str, int dist)
{
	for (; *str != '\0'; str++)
		*str = mapcharacter(*str, -dist);
}


int main(int argc, char *argv[])
{
	char *s = NULL;
	int  d = 0;
	
	if (argc != 4)
		exit(1);
	d = atoi(argv[2]);
	if (d < 1 || d > 25)
	{
		printf("Distance should be > 0 and < 26\n");
		exit(1);
	}
	if (strcmp(argv[1], "encrypt") == 0)
	{
		s = encrypt(argv[3], d);
		printf("%s\n", s);
		free(s);
	}
	else                      /* Assume it is "decrypt" */
	{
		decrypt(argv[3], d);
		printf("%s\n", argv[3]);
	}
	return 0;
}
