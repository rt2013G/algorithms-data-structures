#include "iostream"
using std::swap;
/*
 * Implementation of the Quicksort algorithm, one of the best comparison sorts on a large number of elements.
 * Quicksort uses divide and conquer to split an array A(p, r) into two arrays A(p, q - 1) and A(q + 1, r),
 * where every element of the first one is less than every element of the second one.
 * Those arrays are in turn sorted via recursive calls to Quicksort.
 * In the worst case, the time complexity of Quicksort is Θ(n^2), this happens when each call to partition
 * splits the array into two arrays one of which is empty and the other has n - 1 elements.
 * Since a call to partition costs Θ(n) time, and ordering an empty array just returns with T(0) = Θ(1),
 * the time complexity in the worst case is characterized by the recurrence T(n) = T(n - 1) + Θ(n) + Θ(1),
 * which yields the result Θ(n^2).
 * In the best case, the call to partition splits the array evenly into two parts, therefore the two subproblems
 * each have half the size of the original one, the recurrence is then T(n) = 2T(n/2) + Θ(n), which by case 2
 * of the master theorem yields the result Θ(n log n).
 *
 * "QuicksortIterative.cpp" implements the same algorithm using iteration instead of recursion.
 *
 * "RandomQuicksort.cpp" implements a variation of Quicksort in which the pivot is chosen randomly,
 * thus ensuring that every element of the array is equally likely to be the pivot.
 *
 * "Hybridsort.cpp" implements a variation of Quicksort in which the pivot is chosen by the median of three,
 * on top of that, if the number of elements remaining to sort is smaller than a certain value,
 * the sorting is done via insertion sort.
 * Hybridsort runs 25-30%~ better than normal Quicksort.
 */
void quickSort(int *array, int left, int right);
int partition(int *array, int left, int right);
void printArray(int *array, int size);

int main()
{
    int array[] = {12, 2, 4, 1, 3, 20, 18, 14};
    int size = 8;
    quickSort(array, 0, size - 1);
    printArray(array, size);
    return 0;
}

void quickSort(int *array, int left, int right)
{
    if(left < right) {
        int i = partition(array, left, right);
        quickSort(array, left, i - 1);
        quickSort(array, i + 1, right);
    }
}

int partition(int *array, int left, int right)
{
    int pivot = array[right];
    int i = left - 1;
    for(int j = left; j < right; j++) {
        if(array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[right]);
    return i + 1;
}

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        std::cout << array[i] << std::endl;
}
