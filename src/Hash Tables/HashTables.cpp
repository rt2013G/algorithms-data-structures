#include "iostream"
#include "HashTableChained.h"

int main()
{
    HashTable<int> hashTable(5);
    hashTable.chainedHashInsert(4);
    hashTable.chainedHashInsert(9);
    hashTable.chainedHashInsert(12);
    hashTable.chainedHashInsert(3);
    hashTable.printTable();
    hashTable.chainedHashDelete(3);
    hashTable.printTable();

    HashTable<float> hashTable1(3);
    hashTable1.chainedHashInsert(0.5);
    hashTable1.chainedHashInsert(56372.9);
    hashTable1.chainedHashInsert(219.2);
    hashTable1.chainedHashInsert(2.3);
    hashTable1.printTable();

    return 0;
}
