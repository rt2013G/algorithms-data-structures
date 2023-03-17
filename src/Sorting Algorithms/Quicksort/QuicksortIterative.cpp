#include "iostream"
#include "stack"
using std::swap;
using intStack = std::stack<int>;

void quickSortIterative(int *array, int left, int right);
int partition(int *array, int left, int right);
void printArray(int *array, int size);

int main()
{
    int array[] = {12, 2, 4, 1, 3, 20, 18, 14};
    int size = 8;
    quickSortIterative(array, 0, size - 1);
    printArray(array, size);
    return 0;
}

void quickSortIterative(int *array, int left, int right)
{
    intStack stack;
    stack.push(left);
    stack.push(right);
    while(!stack.empty()) {
        right = stack.top(); stack.pop();
        left = stack.top(); stack.pop();
        int i = partition(array, left, right);
        if(i - 1 > left) {
            stack.push(left);
            stack.push( i - 1);
        }
        if(i + 1 < right) {
            stack.push(i + 1);
            stack.push(right);
        }
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
