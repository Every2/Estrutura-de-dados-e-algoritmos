#include <stdio.h>
#include <stdlib.h>

int findMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

void countingSort(int array[], int n) {
    int max = findMax(array, n);

    int *count = (int *)malloc(sizeof(int) *(max + 1));

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[array[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        while(count[i] > 0) {
            array[index] = i;
            index++;
            count[i]--;
        }
    }
    free(count);
}
