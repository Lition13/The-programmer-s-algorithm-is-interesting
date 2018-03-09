#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
 * use count
 */
int my_strlen_by_count(const char *str)
{
	int count = 0;

	while (*str)
	{
		str ++;
		count ++;
	}
	
	return count;
}

/*
 * use recursion
 */
int my_strlen_by_recursion(const char *str)
{
	if ( *str == '\0'  )
		return 0;
	else
		return my_strlen_by_recursion(str + 1) + 1;

}

/*
 * use pointer
 */
int my_strlen_by_pointer(const char *str)
{
	const char *tmp = str;
	
	while(*(++tmp)){}
	
	return tmp - str;
}

int 
main(int argc, char *args[])
{
	int i = 100000000;
	
	//while((--i) > 0)
	//{
		//my_strlen_by_count(args[1]);   //real:0m0.821s, user:0m0.819s, sys:0m0.000s
		//my_strlen_by_recursion(args[1]); //real:0m1.417s, user:0m1.413s, sys:0m0.000s
		//my_strlen_by_pointer(args[1]); //real:0m0.884s, user:0m0.882s, sys:0m0.000s
	//}
	
	printf("my_strlen:%d\n", my_strlen_by_count(args[1]));
	printf("my_strlen:%d\n", my_strlen_by_recursion(args[1]));
	printf("my_strlen:%d\n", my_strlen_by_pointer(args[1]));
	
	return 0;
}
