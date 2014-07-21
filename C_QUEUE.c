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
	if(!queue->data){
		printf("C_QUEUE: Queue does not exist!\n");
		return -1;
	}
	//Base Case: Empty queue
	if (queue->current_size == 0){
		queue->data[0] = data;
		queue->current_size++;
		return 1; 
	}
	//Case: Queue is full
	if(queue->top +1 >= queue->size){
		printf("C_QUEUE: Queue is full!\n");
		return -1; 
	}
	queue->data[++queue->top] = data;
	queue->current_size++;
	return 1;
}

int c_queue_dequeue(C_QUEUE *queue, int *ret){
	if(!queue->data){
		printf("C_QUEUE: Queue does not exist!\n");
		return -1;
	}
	//Base Case: Queue is Empty
	if(queue->current_size == 0){
		printf("Queue is empty!\n");
		return -1;
	}
	*ret = queue->data[queue->top];
	queue->top--;
	queue->current_size--;
	return 1;
}



int c_queue_delete(C_QUEUE *queue)
{
	free(queue);
	if(queue){
		printf("C_QUEUE: Failed to delete circular queue.\n");
		return -1;
	}
	return 1;
}

