#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>

void insertion_sort(std::vector<int> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;
        for (; vec[j] > key && j > 0; j--) {
            vec[j + 1] = vec[j];
        }
        vec[j + 1] = key;
    }
}

#endif