#include <stdio.h>
#include <stdlib.h>

/* 
Program to simulate FCFS Disk Scheduling algorithm in C
*/

int FCFS(int locs[], int n, int head);

int main() {
	int n;
	printf("Enter number of accesses: ");
	scanf("%d", &n);
	
	int locations[n];
	printf("Enter the locations: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &locations[i]);
	}
	
	int head;
	printf("Enter starting location of the head: ");
	scanf("%d", &head);
	
	int seek_distance = FCFS(locations, n, head);
	
	printf("The total distance covered by the head is: %d\n", seek_distance);

	return 0;
}

int FCFS(int locs[], int n, int head) {
	int distance = 0;
	
	for (int i = 0; i < n; i++) {
		distance += abs(locs[i] - head);
		head = locs[i];
	}
	
	return distance;
}

