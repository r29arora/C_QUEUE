#include "C_QUEUE.h"

int main() {
	C_QUEUE q; 
	c_queue_init(&q,10);

	for(int i = 0; i < 10; i++) {
		printf("Adding %d\n",i);
		c_queue_enqueue(&q, i);
		printf("Top Value: %d\n",q.data[q.top]);
	}

	int val; 
	for(int i = 0; i<10;i++){
		c_queue_dequeue(&q,&val);
		printf("Value Dequeued: %d\n",val);
	}

	return 0; 
}