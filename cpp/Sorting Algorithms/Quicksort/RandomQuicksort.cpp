#include "iostream"
using std::swap;

void randomQuickSort(int *array, int left, int right);
int partition(int *array, int left, int right);
int randomPartition(int *array, int left, int right);
void printArray(int *array, int size);

int main()
{
    int array[] = {12, 2, 4, 1, 3, 20, 18, 14};
    int size = 8;
    randomQuickSort(array, 0, size - 1);
    printArray(array, size);
    return 0;
}

void randomQuickSort(int *array, int left, int right)
{
    if(left < right) {
        int i = randomPartition(array, left, right);
        randomQuickSort(array, left, i - 1);
        randomQuickSort(array, i + 1, right);
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

int randomPartition(int *array, int left, int right)
{
    int i = left + (rand() % (right - left + 1));
    swap(array[i], array[right]);
    return partition(array, left, right);
}

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        std::cout << array[i] << std::endl;
}
