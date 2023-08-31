#include <iostream>
#include <array>

template <typename T, int S>
void selectionSort(std::array<T, S>& array) {
    for (int step {0}; step < S - 1; ++step) {
        int min_idx = step;
        for (int i {step + 1}; i < S; ++i) {
            if (array.at(i) < array.at(min_idx)) {
                min_idx = i;
            }
        }

        std::swap(array.at(min_idx), array.at(step));
    }
}
