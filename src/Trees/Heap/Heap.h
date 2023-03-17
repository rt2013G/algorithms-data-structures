#ifndef ADS_HEAP_H
#define ADS_HEAP_H

#include "iostream"
#include "vector"
#include "string"
using std::swap;
using std::cout;

template <class T>
class Heap {
public:
    Heap();
    int parent(int index);
    int left(int index);
    int right(int index);
    void maxHeapify(int index, int size);
    void buildMaxHeap();
    void insert(T value);
    void printArray();
    void printAsciiTree(int index, const std::string& prefix, bool isLeft);
    int getSize();
    void heapSort();
    std::vector<T> heap;

private:
};

template <class T>
Heap<T>::Heap() {
    this->heap = std::vector<T>();
}

template<class T>
int Heap<T>::parent(int index) {
    return index / 2;
}

template<class T>
int Heap<T>::left(int index) {
    return index * 2 + 1;
}

template<class T>
int Heap<T>::right(int index) {
    return index * 2 + 2;
}

template<class T>
void Heap<T>::maxHeapify(int index, int size) {
    int left = this->left(index);
    int right = this->right(index);
    int max;
    if(left < size && this->heap[index] < this->heap[left]) {
        max = left;
    } else {
        max = index;
    }
    if(right < size && this->heap[max] < this->heap[right]) {
        max = right;
    }
    if(max != index) {
        swap(this->heap[index], this->heap[max]);
        maxHeapify(max, size);
    }
}

template<class T>
void Heap<T>::buildMaxHeap() {
    for(int i = this->heap.size() / 2 - 1; i >= 0; i--) {
        maxHeapify(i, this->heap.size());
    }
}

template<class T>
void Heap<T>::insert(T value) {
    this->heap.push_back(value);
}

template<class T>
void Heap<T>::printArray() {
    for(int i = 0; i < this->heap.size(); i++) {
        cout << "VALUE: " << this->heap[i] << std::endl;
    }
}

template<class T>
void Heap<T>::printAsciiTree(int index, const std::string& prefix, bool isLeft) {
    if(index >= this->heap.size()) {
        return;
    }
    cout << prefix;
    cout << (isLeft ? "|--" : "L--");
    cout << this->heap[index] << std::endl;
    printAsciiTree(left(index), prefix + (isLeft ? "|  " : "    "), true);
    printAsciiTree(right(index), prefix + (isLeft ? "|   " : "    "), false);
}

template<class T>
int Heap<T>::getSize() {
    return this->heap.size();
}

template<class T>
void Heap<T>::heapSort() {
    buildMaxHeap();
    for(int i = getSize() - 1; i >= 0; i--) {
        swap(this->heap[0], this->heap[i]);
        maxHeapify(0, i);
    }
}

#endif //ADS_HEAP_H
