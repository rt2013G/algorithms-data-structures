#include "iostream"
/*
 * Implementation of the Insertion Sort algorithm,
 * which is an efficient algorithm when sorting a small number of elements.
 * The algorithm traverses the array from left to right:
 * Before each iteration, the array contains a sorted partition 1...i-1, while the rest of the array is unsorted.
 * During each iteration, the algorithm compares the next element of the unsorted part of the array, with each element
 * of the sorted part, until it finds its correct position, consequently the array 1...i-1 is still sorted.
 * Therefore, after the last iteration, all n elements are in their correct position, and the array is sorted.
 *
 * In the best case, the time complexity of insertionSort is O(n), this happens when the array is already sorted.
 * In this case, the inner loop is never accessed, leading to a linear time complexity.
 * In the worst case, the time complexity of insertionSort is O(n^2), this happens when the array is sorted in
 * decreasing order. In this case the algorithm has to compare and swap every single element of the array.
 * In the average case, for example when half of the array is sorted, the algorithm has to perform i/2 comparisons,
 * therefore in this case the time complexity of insertionSort is still O(n^2).
 * The space complexity is O(1), as the algorithm works in place.
 */
void insertionSort(int *array, int size);
void swap(int *a, int *b);
void printArray(int *array, int size);

int main()
{
    int array[] = {12, 2, 4, 1, 3, 20, 18, 14};
    int size = 8;
    insertionSort(array, size);
    printArray(array, size);
    return 0;
}

void insertionSort(int *array, int size)
{
    for(int i = 1; i < size; i++) {
        int j = i;
        while(j > 0 && array[j - 1] > array[j]) {
            swap(&array[j - 1], &array[j]);
            j--;
        }
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        std::cout << array[i] << std::endl;
}
