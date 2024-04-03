#include "iostream"

void countingSort(int *array, int len);
void printArray(int *array, int size);

int main()
{
    int array[] = {12, 2, 4, 1, 3, 20, 18, 14};
    int size = 8;
    countingSort(array, size);
    printArray(array, size);

    return 0;
}

void countingSort(int *array, int len)
{
    int max = array[0];
    int min = array[0];
    for(int i = 1; i < len; i++) {
        if(array[i] > max) max = array[i];
        else if(array[i] < min) min = array[i];
    }
    int suppArrayLen = max - min + 1;
    int *suppArray = new int[suppArrayLen];
    for(int i = 0; i < suppArrayLen; i++) {
        suppArray[i] = 0;
    }
    for(int i = 0; i < len; i++) {
        suppArray[array[i] - min]++;
    }
    for(int i = 0, j = 0; i < suppArrayLen; i++) {
        while(suppArray[i] > 0) {
            array[j++] = i + min;
            suppArray[i]--;
        }
    }
    delete[] suppArray;
}

void printArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
        std::cout << array[i] << std::endl;
}
