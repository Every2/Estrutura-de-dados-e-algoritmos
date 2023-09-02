#include <iostream>
#include <array>

template <typename T, std::size_t S>
int binarySearch(std::array<T, S> array, int x, int low, int high) {
    if (low <= high) {
        int mid {low + (high - low) / 2};

        if (array.at(mid) == x) {
            return mid;
        }

        if (array.at(mid) > x) {
            return binarySearch(array, x, low, mid - 1);
        }

        return binarySearch(array, x, mid +  1, high);
    }

    return -1;
}
