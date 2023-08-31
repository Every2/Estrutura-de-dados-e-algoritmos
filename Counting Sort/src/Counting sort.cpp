#include <vector>

int findMax(const std::vector<int>& array) {
    int max {array.at(0)};
    for (int i {1}; i < array.size(); ++i) {
        if (array.at(i) > max) {
            max = array.at(i);
        }
    }
    return max;
}

void countingSort(std::vector<int>& array) {
    int max {findMax(array)};

    std::vector<int> count(max + 1, 0);

    for (int i {0}; i < array.size(); ++i) {
        count.at(array.at(i))++;
    }

    int index {0};
    for (int i {0}; i <= max; ++i) {
        while (count.at(i) > 0) {
            array.at(index) = i;
            index++;
            count.at(i)--;
        }
    }
}
