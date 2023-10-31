#include <stdio.h>

/*
Program to simulate FIFO page replacement algorithm in C
*/

int is_hit(int arr[], int n, int val);

int main() {
	int f;
	printf("Enter the number of files: ");
	scanf("%d", &f);
	
	int frames[f];
	for (int i = 0; i < f; i++) {
		frames[i] = -1;
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
		if (is_hit(frames, i, pages[i])) {
			hit_flag = 1;
			hits++;
		} else {
			frames[pos] = pages[i];			
			pos = (pos+1) % f;
		}
		
		
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

int is_hit(int arr[], int n, int val) {
	for (int i = 0; i < n; i++)
		if (arr[i] == val)
			return 1;
	return 0;
}

