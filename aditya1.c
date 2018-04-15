#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int cylinder;
	struct Node *next;
} *front, *rear, *ptr; 

int queueIt(int cylinderArray[], int size) {
	int i;
	for(i=0;i<size;i++) {
		ptr = (struct Node*) malloc(sizeof(struct Node));
		ptr -> cylinder = cylinderArray[i];
		ptr -> next = NULL;

		if(rear==NULL) {
			front = rear = ptr;
		}
		else {
			rear -> next = ptr;
			rear = ptr;
		}
	}
	return 0;
}

//function to remove cylinders from the ready queue i.e., deleting nodes from the queue
int dequeueIt() {
	ptr = front;
	front = front -> next;
	free(ptr);
	return 0;
}

//function to count number of disk-arm moves
int fcfs(int head) {
	int sumOfArmMoves = 0;

	while(front != NULL) {
		sumOfArmMoves += abs(head - front -> cylinder);
		head = front -> cylinder;
		dequeueIt();
	}
	return sumOfArmMoves;
}

int main() {
	front = NULL; rear = NULL;
	int i;
	int numberOfProcess = 9, head = 143, totalDistance = 0;
	int cylinderArray[] = {86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};

	printf("Position of head : %d\n", head );
	printf("Queue containing cylinder: ");
	for(i = 0; i < numberOfProcess; i++)
		printf("%d ", cylinderArray[i]);

	queueIt(cylinderArray, numberOfProcess);

	totalDistance = fcfs(head);

	printf("\nThe total distance that the disk arm moves is : %d\n", totalDistance);

	return 0;
}

