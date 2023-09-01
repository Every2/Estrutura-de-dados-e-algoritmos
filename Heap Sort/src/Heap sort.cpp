#include <iostream>
#include <vector>

void maxHeapify(std::vector<int>& array, int n, int i) {
    int largest {i};
    int left {2 * i +  1};
    int right {2 * i + 2};

    if (left < n && array.at(left) > array.at(largest)) {
        largest = left;
    }

    if (right < n && array.at(right) > array.at(largest)) {
        largest = right;
    }

    if (largest != i) {
        std::swap(array.at(i), array.at(largest));

        maxHeapify(array, n, largest);
    }
}

void heapSort(std::vector<int>& array) {
    int n {static_cast<int>(array.size())};

    for (int i {n / 2 - 1}; i >= 0; --i) {
        maxHeapify(array, n, i);
    }

    for (int i {n - 1}; i > 0; --i) {
        std::swap(array.at(0), array.at(i));

        maxHeapify(array, i, 0);
    }
}
