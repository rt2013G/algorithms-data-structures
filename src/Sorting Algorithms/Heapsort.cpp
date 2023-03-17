#include "../Trees/Heap/Heap.h"
/*
 * This file is used as a test for the heap and heapsort implementation in "src/Trees/Heap/Heap.h"
 * For simplicity I added the heapsort code directly into the template file.
 * The time complexity of the procedure max-heapify is characterized by the recurrence T(n) <= T(2n/3) + Θ(1),
 * because in the worst case the children's subtrees each have size at most 2n/3. By case 2 of the master theorem,
 * this recurrence yields the result T(n) = O(lg n)
 * Since the call to build-max-heap takes O(n) time and each of the n - 1 calls to max-heapify takes O(lg n) time,
 * the time complexity of Heap Sort is O(n lg n).
 * The space complexity is Θ(1) as the algorithm works in place.
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
