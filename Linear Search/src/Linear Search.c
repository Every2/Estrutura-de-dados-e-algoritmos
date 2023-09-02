int search(int array[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (array[i] == x) {
            return i;
        }
    }
    return -1;
}
