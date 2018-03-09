#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int
main(int argc, char *args[])
{
	int n, reversedInteger = 0, remainder, orginalInteger;

	printf("Enter an integer: %d\n", atoi(args[1]));
	n = atoi(args[1]);

	orginalInteger = n;

	while( n != 0 )
	{
		remainder = n % 2;
		printf("remainder:%d, reversed:%d, n:%d\n", remainder, reversedInteger, n);
		reversedInteger = reversedInteger * 10 + remainder;

		n /= 2;
	}

	if (orginalInteger == reversedInteger)
		printf("%d is a parlindrome.\n", orginalInteger);
	else
		printf("%d is not ad palindrome.\n", orginalInteger);

	return 0;
}
