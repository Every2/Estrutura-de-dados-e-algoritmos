#include <vector>
#include <iostream>

int getMax(const std::vector<int>& array) {
    int max {array.at(0)};
    for (int i {1}; i < array.size(); ++i) {
        if (array.at(i) > max) {
            max = array.at(i);
        }
    }
    return max;
}

void countingSort(std::vector<int>& array, int place) {
    int n {static_cast<int>(array.size())};
    std::vector<int> output (n);
    int max {getMax(array)};
    std::vector<int> count (max + 1, 0);

    for (int i {0}; i < n; ++i) {
        count.at((array.at(i) / place) % 10)++;
    }

    for (int i {1}; i < max; ++i) {
        count.at(i) += count.at(i - 1);
    }

    for (int i = array.size() - 1; i >= 0; --i) {
        output.at(count.at((array.at(i) / place) % 10) - 1) = std::move(array.at(i));
        count.at((array.at(i) / place) % 10)--;
    }

    array = std::move(output);
}

void radixSort(std::vector<int>&  array) {
    int max = getMax(array);

    for (int place {1}; max / place > 0; place *= 10) {
        countingSort(array, place);
    }
}
