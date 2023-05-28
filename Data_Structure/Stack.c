#include "stdio.h"


#define STACK_SIZE 5
int stack_array[STACK_SIZE];
int sp = -1; //stack pointer

void Push(int data)
{
	if (sp == STACK_SIZE-1)
	{
		printf("Stack Overflow\n");
		return; // to exit the push function
	}

	else
	{
		sp++;
		stack_array[sp] = data;
	}
}

void print_stack(void)
{
	int i;

	for (i=0; i<=sp; i++)
		printf("%d ",stack_array[i]);

	printf("\n");
}

int Pop()
{
	// check that stack is not empty
	if (sp == -1)
	{
		printf("Stack is Empty\n");
		return -1; // -1 (to indicate error)
	}

	else
	{
		int data = stack_array[sp];
		sp--;
		return data;
	}
}

int main ()
{
	/*	These are written once instead of fflush()	*/
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	Push(3);
	Push(7);
	Push(11);
	Push(22);
	Push(2);

	print_stack();
	int x = Pop();
	printf("popped element = %d\n",x);

	print_stack();

	return 0;
}