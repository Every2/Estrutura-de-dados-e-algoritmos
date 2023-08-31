#include <array>

template <typename T, int S>
void insertionSort(std::array<T, S>& array) {
    for (int i {1}; i < array.size(); ++i) {
        int key = array.at(i);
        int j = i - 1;

        while (key < array.at(j) &&  j >= 0) {
            array.at(j + 1) = array.at(j)
            --j;
        }
        array.at(j + 1) = key;
    }
}
