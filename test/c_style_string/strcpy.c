#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *
my_strcpy(char *dest, const char *src)
{
	while( *dest++ = *src++  ) {  }

	return dest;
}


int
main(int argc, char *args[])
{
	char *src = "Hello World";
	char dest[strlen(src)];
	char* s = my_strcpy(dest, src);
	printf("dest:%s, s:%s\n", dest, s);

	return 0;
}
