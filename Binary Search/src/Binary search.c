int binarySearch(int array[], int x, int low, int high) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x) {
            return mid;
        }

        if (array[mid] > x) {
            return binarySearch(array, x, low, mid - 1);
        }

        return binarySearch(array, x, mid + 1, high);
    }

    return -1;    
}
