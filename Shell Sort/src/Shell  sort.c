void shellSort(int array[], int n) {
    for (int i = n / 2; i > 0; i /= 2) {
        for (int j = i; j < n; j += 1) {
            int temp = array[j];
            int y;
            for (y = j; y >= i && array[y - i] > temp; y -= i) {
                array[y] = array[y - i];
            }
            array[y] = temp;
        }
    }
}
