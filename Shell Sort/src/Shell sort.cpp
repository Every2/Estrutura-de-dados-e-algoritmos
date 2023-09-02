#include <array>
#include <iostream>

template <typename T, int S>
void shellSort(std::array<T, S>& array) {
    for (int i {static_cast<int>(array.size()) / 2}; i > 0; i /= 2)  {
        for (int j {i}; j < static_cast<int>(array.size()); j += 1) {
            int temp {array.at(j)};
            int y;
            for (y = j; y >= i && array.at(y - i) > temp; y -= i) {
                array.at(y) = array.at(y - i);
            }
            array.at(y) = temp;
        }
    }
} 
