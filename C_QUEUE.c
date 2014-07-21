/*

Filename: "C_QUEUE.c"

Simple Circular Queue Implementation in C
Author: Rajul Arora
GitHub: r29arora.github.com

*/

#include "C_QUEUE.h"

int c_queue_init(C_QUEUE *queue, int size)
{
	queue->size = size; 
	queue->top = 0;
	queue->bottom = 0;
	queue->current_size = 0;
	queue->data = malloc(sizeof(int)*size);
	if (!queue->data){
		printf("C_QUEUE: Failed initializing circular queue.\n");
		return -1; 
	} 
	return 1;
}

int c_queue_enqueue(C_QUEUE *queue, int data){
	//Base Case: Empty queue
	if (queue->current_size == 0){
		queue->data[0] = data;
		queue->current_size++;
		return 1; 
	}
	//Case: Queue is full
	if(queue->current_size+1 > queue->size){
		printf("C_QUEUE: Queue is full!\n");
		return -1; 
	}
	//If we have reached the end of the array
	//Make the pointer to the end 0.
	if (queue->bottom+1 == queue->size){
		queue->bottom = 0;
	}
	//Increment pointer to the bottom of the queue and add data to it
	queue->data[++queue->bottom] = data;
	//Increment the overall size of the queue
	queue->current_size++;
	return 1;
}

int c_queue_dequeue(C_QUEUE *queue, int *ret){
	//Base Case: Queue is Empty
	if(queue->current_size == 0){
		printf("Queue is empty!\n");
		return -1;
	}
	//Case when removing an item from the top of the queue reaches
	//the end of the array
	if (queue->top +1 == queue->size){
		queue->top = 0;
	}
	//Store the value being removed from the queue into ret
	//Increment top to be the next element in the array
	*ret = queue->data[queue->top++];
	//Decrease the overall size of the queue
	queue->current_size--;
	return 1;
}

int c_queue_print(C_QUEUE queue)
{	
	if(!queue.data){
		return -1;
	}
	if(queue.current_size == 0){
		printf("Trying to Print Empty Queue!\n");
		return -1;
	}
	int x=queue.top;
	while(x!=queue.bottom){
		printf("%d\n",queue.data[x++]);
		if(x==queue.size){
			x=0;
		}
	}
	printf("%d\n",queue.data[queue.bottom]);
	return 1;
}

int c_queue_delete(C_QUEUE *queue)
{
	free(queue->data);
	queue->size =0;
	queue->current_size=0;
	queue->top =0;
	queue->bottom =0;
	return 1;
}

