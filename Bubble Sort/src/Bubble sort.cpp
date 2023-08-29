#include <array>

template <typename T, int S>
void bubbleSort(std::array<T, S>& array) {
    bool swapped {false};
    for (int idx {0}; idx < array.size() - 1; ++idx) {
        for (int i {0}; i < array.size() - idx - 1; ++i) {
            if (array.at(i) > array.at(i + 1)) {
                std::swap(array.at(i), array.at(i + 1));
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
