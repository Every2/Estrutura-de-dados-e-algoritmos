#include <array>

template <typename T, int S>
int search(std::array<T, S> array, int x) {
    for (int i {0}; i < static_cast<int>(array.size()); ++i) {
        if (array.at(i) == x) {
            return i;
        }
    }
    return -1;
}
