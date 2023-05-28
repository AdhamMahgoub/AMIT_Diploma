#include "stdio.h"


#define Queue_SIZE 5
int queue_array[Queue_SIZE];
int Rear = -1;
int Front = -1;

void enQueue (int data)
{
	// check if queue is full
	if (Front == Queue_SIZE-1)
	{
		printf("Queue is full \n");
		return;
	}

	else
	{
		// check if empty (this is 1st entry)
		if (Rear == -1 && Front == -1)
		{
			Rear = 0;
			Front = 0;

			queue_array[Rear] = data; // or queue_array[Front] // they're the same in this case
		}

		// if there is still space
		else
		{
			Front++;
			queue_array[Front] = data;
		}
	}
}

int deQueue (void)
{
	// check if empty
	if (Rear == -1)
	{
		printf("Queue is empty \n");
		return -1;
	}

	else
	{
		int data;
		// if this is the last element
		if (Rear == Front)
		{
			data = queue_array[Rear];
			Rear++;

			// return to initial conditions
			Rear = -1;
			Front = -1;

			return data;
		}

		else
		{
			data = queue_array[Rear];
			Rear++;
			return data;
		}
	}
}

void print_Queue(void)
{
	int i;
	for (i=Rear; i<=Front; i++)
		printf("%d ",queue_array[i]);
	printf("\n");
}


int main ()
{
	/*	These are written once instead of fflush()	*/
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	enQueue(3);
	enQueue(4);
	enQueue(5);
	enQueue(7);
	enQueue(9);

	print_Queue();

	int x = deQueue();
	printf("deQueue = %d\n",x);
	print_Queue();

	return 0;
}