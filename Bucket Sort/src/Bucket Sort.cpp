#include <iostream>
#include <vector>
#include <algorithm>

void insertionSort(std::vector<int>& bucket) {
    for (int i {1}; i < bucket.size(); ++i) {
        int key {bucket.at(i)};
        int j {i -  1};

        while (j >=  0 && bucket.at(j) > key) {
            bucket.at(j +  1) = bucket.at(j);
            --j;
        }

        bucket.at(j +  1) = key;
    }
}

void bucketSort(std::vector<int>& array) {
    int n {static_cast<int>(array.size())};
    if (n ==  0) return;

    int maxVal {*max_element(array.begin(), array.end())};
    int minVal {*min_element(array.begin(), array.end())};

    int range {maxVal - minVal + 1};
    int bucketSize {5};
    int numBuckets {(range + bucketSize - 1) / bucketSize};
    std::vector<std::vector<int>> buckets(numBuckets);

    for (int i {0}; i < n; ++i) {
        int index {(array.at(i) - minVal) / bucketSize};
        buckets.at(index).push_back(std::move(array.at(i)));
    }

    for (int i {0}; i < numBuckets; ++i) {
        insertionSort(buckets.at(i));
    }

    int index {0};
    for (int i {0}; i < numBuckets; ++i) {
        for (int j {0}; j < buckets.at(i).size(); ++j) {
            array.at(index++) = std::move(buckets.at(i).at(j));
        }
    }
}
