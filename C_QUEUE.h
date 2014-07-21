/*

Filename: "C_QUEUE.h"

Simple Circular Queue Implementation in C
Author: Rajul Arora
GitHub: r29arora.github.com

*/

#include <stdio.h>
#include <stdlib.h>

#ifndef C_QUEUE_H
#define C_QUEUE_H

typedef struct C_QUEUE {
	int *data; 
	int size;
	int current_size;
	int top;
	int bottom; 
} C_QUEUE;

int c_queue_init(C_QUEUE *queue, int size);
/*
	Initialize Circular Queue

	Params: 
	queue: pointer to the queue that is to be initialized
	size: overall size of the queue that is to be initialized

	Returns -1 for error, 1 for success

*/

int c_queue_enqueue(C_QUEUE *queue, int data);
/*
	Add an element to an existing circular queue
	Params: 
	queue: pointer to the queue
	data: data to be added to the queue

	Returns -1 for error, 1 for success
*/


int c_queue_dequeue(C_QUEUE *queue, int *ret);
/*
	Remove an element from the top of the circular queue
	Params: 
	queue: pointer to the queue
	ret: pointer to the return value

	Returns -1 for error, 1 for success
*/

//void c_queue_print(C_QUEUE queue);
/*
	Prints all the values currently in the queue
	Params:
	queue: queue that is to be printed
*/

int c_queue_print(C_QUEUE queue);
/*
	Prints the entire circular queue
	Params:
	queue: queue to be printed

	Returns -1 for failed print, 1 for success
*/

int c_queue_delete(C_QUEUE *queue);
/*
	Delete Circular Queue

	Params:
	queue: pointer to the queue that is to be deleted
*/


#endif