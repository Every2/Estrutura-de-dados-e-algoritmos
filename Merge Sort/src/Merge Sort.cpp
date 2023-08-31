#include <iostream>
#include <vector>

template <typename T>
void merge(std::vector<T>& arr, int left, int middle, int right) {
    int n1 {middle - left + 1};
    int n2 {right - middle};

    std::vector<T> L(std::make_move_iterator(arr.begin() + left),
                     std::make_move_iterator(arr.begin() + middle + 1));
    std::vector<T> R(std::make_move_iterator(arr.begin() + middle + 1),
                     std::make_move_iterator(arr.begin() + right + 1));

    int i {0}, j {0}, k {left};
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = std::move(L[i]);
            ++i;
        }
        else {
            arr[k] = std::move(R[j]);
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = std::move(L[i]);
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = std::move(R[j]);
        ++j;
        ++k;
    }
}

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int middle {left + (right - left) / 2};

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}
