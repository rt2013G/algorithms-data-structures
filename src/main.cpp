#include "iostream"

#include "01-sorting/insertion_sort.hpp"

int main(void) {
    std::vector<int> vec{1, 10, 3, 2, 13, 2, 19, 5, 16};
    insertion_sort(vec);
    for (auto &num : vec) {
        std::cout << num << std::endl;
    }
}