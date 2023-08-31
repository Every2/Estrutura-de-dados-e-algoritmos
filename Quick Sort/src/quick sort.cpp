#include <vector>

template <typename T>
int partition(std::vector<T>& array, int low, int high) {
    int pivot {array.at(high)};
    int i {low - 1};

    for (int j {low}; j <= high - 1; ++j) {
        if (array.at(j) <= pivot) {
            ++i;
            std::swap(array.at(i), array.at(j));
        }
    }
    std::swap(array.at(i + 1), array.at(high));
    return i +  1;
}

template <typename T>
void quickSort(std::vector<T>& array, int low, int high) {
    if (low < high) {
        int pi {partition(array, low, high)};

        quickSort(array, low, pi -  1);
        quickSort(array, pi + 1, high);
    }
}
