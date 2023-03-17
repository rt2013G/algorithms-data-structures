#include "../Trees/Heap/Heap.h"
/*
 * This file is used as a test for the heap and heapsort implementation in "src/Trees/Heap/Heap.h"
 * For simplicity I added the heapsort code directly into the template file.
 */
using intHeap = Heap<int>;

int main()
{
    intHeap heap;
    heap.insert(5);
    heap.insert(2);
    heap.insert(3);
    heap.insert(10);
    heap.insert(4);
    heap.insert(50);
    heap.heapSort();
    heap.printArray();
    return 0;
}
