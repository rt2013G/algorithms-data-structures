#include "iostream"
using std::swap;

void HybridSort(int *array, int left, int right);
int partition(int *array, int left, int right);
void medianOfThree(int *array, int left, int right);
void insertionSort(int *array, int left, int right);
void printArray(int *array, int size);
const int M = 10;

int main()
{
    int array[] = {12, 2, 4, 1, 3, 20, 18, 14, 23, 31, 5, 4, 3, 11, 19, 22, 27, 88, 34, 31, 12, 55, 62, 23, 75, 51};
    int size = sizeof(array) / sizeof(int);
    HybridSort(array, 0, size - 1);
    printArray(array, size);
    return 0;
}

void HybridSort(int *array, int left, int right)
{
    if((right - left) > M) {
        medianOfThree(array, left, right);
        int i = partition(array, left + 1, right - 1);
        HybridSort(array, left, i - 1);
        HybridSort(array, i + 1, right);
    }
    insertionSort(array, left, right);
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

void medianOfThree(int *array, int left, int right)
{
    int mid = (left + right) / 2;
    swap(array[mid], array[right - 1]);
    if(array[left] > array[right - 1]) {
        swap(array[left], array[right - 1]);
    }
    if(array[left] > array[right]) {
        swap(array[left], array[right]);
    }
    if(array[right - 1] > array[right]) {
        swap(array[right - 1], array[right]);
    }
}

void insertionSort(int *array, int left, int right)
{
    for(int i = left + 1; i < right + 1; i++) {
        int j = i;
        while(j > left && array[j - 1] > array[j]) {
            swap(array[j - 1], array[j]);
            j--;
        }
    }
}

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        std::cout << array[i] << std::endl;
}
