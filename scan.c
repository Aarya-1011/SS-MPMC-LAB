#include <stdio.h>

/* 
Program to simulate SCAN (elevator) Disk Scheduling algorithm in C

(Here, we're assuming the head mvoes left first, then right)
*/

int SCAN(int locs[], int n, int head);

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
	
	int seek_distance = SCAN(locations, n, head);
	
	printf("The total distance covered by the head is: %d\n", seek_distance);

	return 0;
}

int SCAN(int locs[], int n, int head) {
	int start = head;
	int distance = 0;
	
	for (int i = 0; i < n; i++) {
		if (locs[i] < start) {
			distance -= locs[i] - head;
			head = locs[i];
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (locs[i] > start) {
			distance += locs[i] - head;
			head = locs[i];
		}
	}
	
	return distance;
}

