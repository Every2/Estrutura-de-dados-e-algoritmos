void bubbleSort(int array[], int size) {
    for (int idx = 0; idx < size - 1; idx++) {
        int swapped = 0;
        for (int i = 0; i < size - idx - 1; i++) {
            if (array[i] > array[i + 1]) {
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;

                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}
