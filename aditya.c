#include<stdio.h>
int mergeUser(int Arr_time[], int ser_time[], int remser_time[], int beg, int mid, int end) {
	int i = beg, j = mid + 1, k = 0;
	int tempArrival[end - beg + 1], tempService[end - beg + 1], tempRemaining[end - beg + 1];	

	while(i <= mid && j <= end) {
		if(Arr_time[i] < Arr_time[j]) {
			tempArrival[k] = Arr_time[i];
			tempService[k] = ser_time[i];
			tempRemaining[k] = remser_time[i];
			i++;
		}
		else {
			tempArrival[k] = Arr_time[j];
			tempService[k] = ser_time[j];
			tempRemaining[k] = remser_time[j];
			j++;
		}
		k++;
	}

	if(i > mid) {
		while(j <= end){
			tempArrival[k] = Arr_time[j];
			tempService[k] = ser_time[j];
			tempRemaining[k] = remser_time[j];
			j++; k++;
		}
	}
	else {
			tempArrival[k] = Arr_time[i];
			tempService[k] = ser_time[i];
			tempRemaining[k] = remser_time[i];
			i++; k++;
	}

	for(i = beg, k = 0; i <= end; i++, k++) {
		Arr_time[i] = tempArrival[k];
		ser_time[i] = tempService[k];
		remser_time[i] = tempRemaining[k];
	}

	return 0;
}

//mergesortUser will sort the arrays recursively
int mergesortUser(int Arr_time[], int ser_time[], int remser_time[], int beg, int end) {
	if(beg == end)
		return 0;
	int mid = (beg + end) / 2;
	mergesortUser(Arr_time, ser_time, remser_time, beg, mid);
	mergesortUser(Arr_time, ser_time, remser_time, mid + 1, end);
	mergeUser(Arr_time, ser_time, remser_time, beg, mid, end);

	return 0;
}

int getHighestPriority(int priority[], int ser_time[], int remser_time[], int limit) {
	int highestPriority = 0, iter;
	for(iter = 1; iter < limit; iter++) {

		if(priority[highestPriority] == priority[iter]) {
			if((ser_time[iter] - remser_time[iter]) < (ser_time[highestPriority] -remser_time[highestPriority])) {
				highestPriority = iter;
			}
		}
		else if(priority[highestPriority] < priority[iter]) {
				 highestPriority = iter;
		    }
	} 
	return highestPriority;
}

int main() {
	int numberOfProcess, sumArrival = 0, sumRemaining = 0, sum = 0, timeCounter = 0;
	printf("Enter number of processes : ");
	scanf("%d", &numberOfProcess);

	int Arr_time[numberOfProcess], priority[numberOfProcess];
	int ser_time[numberOfProcess], remser_time[numberOfProcess], waitingTime = 0;

	int i = 0;

	printf("\n");
	for( ; i < numberOfProcess; i++) {
		printf("\nEnter arrival time of process P%d : ", i + 1);
		scanf("%d", &Arr_time[i]);

		printf("\nEnter service time of process P%d : ", i + 1);
		scanf("%d", &ser_time[i]);

		priority[i] = 0;
		remser_time[i] = ser_time[i];

		sumArrival += Arr_time[i];
		sumRemaining += remser_time[i];
	}
}
