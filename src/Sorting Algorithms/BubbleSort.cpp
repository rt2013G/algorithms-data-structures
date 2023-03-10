#include "iostream"
/*
 * Implementation of the Bubble Sort Algorithm.
 * Bubble Sort is the simplest sorting algorithm and behaves as follows:
 * Starting from the beginning of the array, at each iteration of the inner loop we compare
 * the jth element of the array with the jth+1 element, if the former is larger, then we swap the two elements.
 *
 * Prior to each iteration, the subarray n-i...n is ordered, this holds true after the end of the iteration.
 * During the first iteration, the algorithm performs n-1 comparisons and at most n-1 swaps,
 * during the second iteration, the algorithm performs n-2 comparisons and at most n-2 swaps, and so on,
 * during the last iteration, the algorithm performs 1 comparison and at most 1 swap.
 * Therefore, the time complexity of Bubble Sort is (n-1)(n-2)...1, which by Gauss formula is [(n-1)(n-1+1)]/2 =
 * [n(n-1)]/2 = O(n^2). Space complexity is O(1) because the algorithm operates in place.
 */
void bubbleSort(int *array, int size);
void swap(int *a, int *b);
void printArray(int *array, int size);

int main()
{
    int array[] = {12, 2, 4, 1, 3, 20, 18, 14};
    int size = 8;
    bubbleSort(array, size);
    printArray(array, size);
    return 0;
}

void bubbleSort(int *array, int size)
{
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
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
