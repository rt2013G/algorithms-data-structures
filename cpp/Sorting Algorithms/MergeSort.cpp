#include "iostream"
/*
 * Implementation of the Merge Sort algorithm.
 * Merge Sort is a sorting algorithm that follows the divide and conquer paradigm:
 * During the divide step, the unsorted array is split into two parts of half the size,
 * during each recursive call, the arrays are sorted. Finally, in the combine step, the sorted arrays are merged
 * back into original array that is now sorted.
 * In the merge procedure, prior to the first iteration, k = left, therefore the array left...k is empty.
 * Furthermore, since i = j = 1, array_a[i] and array_b[j] are the smaller elements of their respective arrays
 * yet to be copied into array.
 * During each iteration, the array left...k contains the smallest k-p elements
 * due to the condition array_a[i] <= array_b[j].
 * At the end, the subarray left...k contains the smallest k-p elements that are now sorted.
 * The merge procedure has a time complexity of Θ(n), where n = right - left + 1.
 * This is because all operations used in the procedure have constant time complexity, while the total complexity
 * of the for loops is Θ(size_a + size_b) = Θ(n).
 * The mergeSort time complexity is characterized by the recurrence T(n) = 2T(n/2) + Θ(n), which comes from the
 * fact that the divide step takes Θ(1) time, the combine step (merge) takes Θ(n) time, while each recursive call
 * splits the problems into two subproblems of size n/2.
 * By case 2 of the master theorem, this recurrence characterizes the time complexity of mergeSort as Θ(nlog_2n)
 * The space complexity is O(n), because the algorithm does not operate in place
 * but requires two auxiliary arrays whose total size is n.
 */
void mergeSort(int *array, int left, int right);
void merge(int *array, int left, int mid, int right);
void printArray(int *array, int size);

int main()
{
    int array[] = {12, 2, 4, 1, 3, 20, 18, 14};
    int size = 8;
    mergeSort(array, 0, size - 1);
    printArray(array, size);
    return 0;
}

void mergeSort(int *array, int left, int right)
{
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void merge(int *array, int left, int mid, int right)
{
    int size_a = mid - left + 1;
    int size_b = right - mid;
    int *array_a = new int[size_a];
    int *array_b = new int[size_b];
    for(int i = 0; i < size_a; i++) {
        array_a[i] = array[left + i];
    }
    for(int j = 0; j < size_b; j++) {
        array_b[j] = array[mid + j + 1];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i < size_a && j < size_b) {
        if(array_a[i] <= array_b[j])
            array[k++] = array_a[i++];
        else
            array[k++] = array_b[j++];
    }
    while(i < size_a)
        array[k++] = array_a[i++];
    while(j < size_b)
        array[k++] = array_b[j++];
    delete[] array_a;
    delete[] array_b;
}

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        std::cout << array[i] << std::endl;
}
