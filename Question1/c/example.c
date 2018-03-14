#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

void
strrev(unsigned char * str)
{
	int i;
	int j;
	unsigned char a;
	unsigned len = strlen((const char *) str);

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
	}
}

int
itoa(int num, unsigned char* str, int len, int base)
{
	int sum = num;
	int i = 0;
	int digit;
	
	if (len == 0)
		return -1;
	do
	{
		digit = sum % base;
		if (digit < 0xA)
			str[i++] = '0' + digit;
		else
			str[i++] = 'A' + digit - 0xA;
			sum /= base;
																
	}while (sum && (i < (len - 1)));
	
	if (i == (len - 1) && sum)
		return -1;
	
	str[i] = '\0';
	strrev(str);
	
	return 0;
}

int
itoa_rev(int num, unsigned char* str, int len, int base)
{
	int sum = num;
	int i = 0;
	int digit;
	
	if (len == 0)
		return -1;
	do
	{
		digit = sum % base;
		if (digit < 0xA)
			str[i++] = '0' + digit;
		else
			str[i++] = 'A' + digit - 0xA;
			sum /= base;
																
	}while (sum && (i < (len - 1)));
	
	if (i == (len - 1) && sum)
		return -1;
	
	str[i] = '\0';
	
	return 0;
}

int
main(int argc, char ** args)
{
	int i = atoi(args[1]);

 
	while (1 == 1)
	{	
		char num_str_2[12] = {'\0'}; 
		char num_str_8[12] = {'\0'}; 
		char num_str_10[12] = {'\0'};
		char num_str_rev_2[12] = {'\0'}; 
		char num_str_rev_8[12] = {'\0'}; 
		char num_str_rev_10[12] = {'\0'};

		itoa(i,num_str_2, sizeof(num_str_2), 2);		
		itoa(i,num_str_8, sizeof(num_str_8), 8);		
		itoa(i,num_str_10, sizeof(num_str_10), 10);

		itoa_rev(i,num_str_rev_2, sizeof(num_str_rev_2), 2);		
		itoa_rev(i,num_str_rev_8, sizeof(num_str_rev_8), 8);		
		itoa_rev(i,num_str_rev_10, sizeof(num_str_rev_10), 10);

		
		if (!strcmp(num_str_2, num_str_rev_2) 
				&& !strcmp(num_str_8, num_str_rev_8) 
				&& !strcmp(num_str_10, num_str_rev_10))
			break;
		
		i++;
	}

	printf("%d\n", i);
}
