/*
 * Implementation of a Hash Table with collisions resolves by chaining.
 * The linked list used for chaining is implemented with the class Node, where every node may store any data T.
 * The hash function uses the division method, by converting whatever T may be into an integer*.
 */
#ifndef ADS_HASHTABLECHAINED_H
#define ADS_HASHTABLECHAINED_H

template <class T>
class Node
{
public:
    explicit Node(T data);
    ~Node();
    void insertAfter(Node *node); // Adds "node" after this node
    T getData();
    Node *next;
    Node *prev;
private:
    T data;
};

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
Node<T>::~Node() {
    Node *head = this;
    while(head != nullptr) {
        Node *curr = head;
        head = head->next;
        curr = nullptr;
    }
}

template<class T>
void Node<T>::insertAfter(Node *node) {
    if(node == nullptr) return;
    if(this->next != nullptr) {
        node->next = this->next;
        node->next->prev = node;
    }
    this->next = node;
    node->prev = this;
}

template<class T>
T Node<T>::getData() {
    return this->data;
}

template<class T>
class HashTable
{
public:
    explicit HashTable(int slots);
    void chainedHashInsert(T data);
    void chainedHashDelete(T data);
    Node<T> *chainedHashSearch(T data);
    int hashFunction(T data);
    void printTable();
    Node<T> **chains;
private:
    int slots{};
};

template<class T>
HashTable<T>::HashTable(int slots) {
    this->slots = slots;
    this->chains = new Node<T> *[this->slots];
    for(int i = 0; i < this->slots; i++) {
        this->chains[i] = nullptr;
    }
}

template<class T>
void HashTable<T>::chainedHashInsert(T data) {
    int index = this->hashFunction(data);
    auto *newNode = new Node<T>(data);
    if(newNode == nullptr) return;
    if(this->chains[index] == nullptr) {
        this->chains[index] = newNode;
    } else {
        newNode->insertAfter(this->chains[index]);
        this->chains[index] = newNode;
    }
}

template<class T>
void HashTable<T>::chainedHashDelete(T data) {
    int index = hashFunction(data);
    if(this->chains[index] == nullptr) return;
    this->chains[index] = nullptr;
}

template<class T>
Node<T> *HashTable<T>::chainedHashSearch(T data) {
    int index = this->hashFunction(data);
    Node<T> *curr = this->chains[index];
    while(curr != nullptr && curr->getData() != data) {
        curr = curr->next;
    }
    return curr;
}

template<class T>
int HashTable<T>::hashFunction(T data) {
    int intVal = (int) data; // *this is bad, but I didn't want to delve too deep into the hash function
    return intVal % this->slots;
}

template<class T>
void HashTable<T>::printTable() {
    for(int i = 0; i < this->slots; i++) {
        std::cout << "Nodes at hash = " << hashFunction(i) << ": ";
        Node<T> *curr = this->chains[i];
        while(curr != nullptr) {
            std::cout << curr->getData() << " - ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

#endif //ADS_HASHTABLECHAINED_H
