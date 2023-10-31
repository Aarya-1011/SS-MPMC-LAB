#include <stdio.h>

/*
Program to simulate LRU page replacement algorithm in C
*/

int search(int arr[], int n, int val);

int least(int arr[], int n);

int main() {
	int f;
	printf("Enter the number of files: ");
	scanf("%d", &f);
	
	int frames[f];
	int used[f];
	for (int i = 0; i < f; i++) {
		frames[i] = -1;
		used[i] = -1;
	}
	
	int p;
	printf("Enter the number of pages: ");
	scanf("%d", &p);
	
	int pages[p];
	
	printf("Enter the pages\n");
	for (int i = 0; i < p; i++) {
		scanf("%d", &pages[i]);
	}
	
	int hits = 0;
	int pos = 0;
	
	int hit_flag = 0;
	for (int i = 0; i < p; i++) {
		pos = search(frames, f, pages[i]);
		
		if (pos != -1) {
			hit_flag = 1;
			hits++;
		} else {
			pos = least(used, f);
			frames[pos] = pages[i];
			used[pos] = 0;		
		}
		used[pos]++;
		
		
		printf("Page %d requested. Frames: ", pages[i]);
		for (int j = 0; j < f; j++) {
			if (frames[j] != -1)
				printf("%d ", frames[j]);
			else printf("- ");
		}
		if (hit_flag) {
			printf(" (*)");
			hit_flag = 0;
		} else {
			printf(" (-)");
		}
		printf("\n");
	}

	printf("Number of hits: %d\n", hits);
	printf("Number of misses: %d\n", p-hits);

	return 0;
}

int search(int arr[], int n, int val) {
	for (int i = 0; i < n; i++)
		if (arr[i] == val)
			return 1;
	return -1;
}

int least(int arr[], int n) {
	int x = 0;
	
	for (int i = 0; i < n; i++) {
		if (arr[x] > arr[i])
			x = i;
	}
	
	return x;
}

