#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Node class template
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val); // Constructor to initialize the node with a value
};

// Sorted Linked List class template
template <typename T>
class SortedLinkedList {
private:
    Node<T>* head; // Pointer to the head of the linked list

public:
    SortedLinkedList(); // Constructor to initialize an empty list

    void insert(T value);  // Inserts a value in sorted order
    void remove(int index);  // Removes an element at a given index

    // Overloaded operators
    template <typename U>
    friend ostream& operator<<(ostream& os, const SortedLinkedList<U>& list); // Prints the linked list
    T operator[](int index); // Access element at a given index

    ~SortedLinkedList();  // Destructor to free memory
};

// Global variable to track the size of the linked list
static int SIZE = 0;

// Node constructor
template <typename T>
Node<T>::Node(T val) {
    data = val;
    next = nullptr;
}

// SortedLinkedList constructor initializes an empty list
template <typename T>
SortedLinkedList<T>::SortedLinkedList() {
    head = nullptr;
}

// Overloaded << operator to print the list in a formatted way
template <typename T>
ostream& operator<<(ostream& os, const SortedLinkedList<T>& list) {
    Node<T>* current = list.head;
    os << "[";

    while (current != nullptr) {
        os << current->data;
        if (current->next != nullptr) {
            os << ", ";
        }
        current = current->next;
    }
    os << "]";
    return os;
}

// Overloaded [] operator to access elements by index
template <typename T>
T SortedLinkedList<T>::operator[](int index) {
    Node<T>* current = head;

    // Check if index is within bounds
    if (index >= SIZE || index < 0) {
        cout << "OUT OF BOUNDS" << endl;
        throw out_of_range("Index out of bounds");
    }

    // Traverse to the required index
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

// Insert a value into the sorted linked list
template <typename T>
void SortedLinkedList<T>::insert(T val) {
    Node<T>* input = new Node<T>(val);

    // Case 1: If list is empty
    if (head == nullptr) {
        head = input;
        SIZE++;
        return;
    }
    // Case 2: Insert at the head if value is smaller than the first element
    else if (input->data < head->data) {
        input->next = head;
        head = input;
        SIZE++;
        return;
    }
    // Case 3: Traverse and find the correct position to insert
    else {
        Node<T>* current = head;
        while (current->next != nullptr && current->next->data < val) {
            current = current->next;
        }
        input->next = current->next;
        current->next = input;
        SIZE++;
    }
}

// Remove an element at a given index
template <typename T>
void SortedLinkedList<T>::remove(int index) {
    Node<T>* current = head;

    // Case 1: If list is empty, nothing to remove
    if (head == nullptr) {
        cout << "List is empty, nothing to remove." << endl;
        return;
    }

    // Case 2: Removing the first element
    if (index == 0) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        SIZE--;
        return;
    }
    // Case 3: Removing an element at a valid index
    else if (index < SIZE) {
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
        SIZE--;
        return;
    }
    // Case 4: Index is out of bounds
    else {
        cout << "No Change,(OUT OF BOUNDS)" << endl;
    }
}

// Destructor to free allocated memory
template <typename T>
SortedLinkedList<T>::~SortedLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
}

int main() {
    // Testing with integers
    SortedLinkedList<int> list;
    list.insert(5);
    list.insert(7);
    list.insert(9);
    list.insert(2);
    cout << list << endl;
    // Print the sorted list: [2, 5, 7, 9]
    cout << list[2] << endl;
    list.remove(1);
    cout << list << endl;
    list.remove(100);

    // Testing with strings
    SortedLinkedList<string> listStr;
    listStr.insert("Hello");
    listStr.insert("World");
    listStr.insert("apple");
    cout << listStr << endl;
    // Print the sorted list
    cout << listStr[1] << endl;
    listStr.remove(2);
    cout << listStr << endl;
    listStr.remove(100);

    // Testing with floats
    SortedLinkedList<float> listfloat;
    listfloat.insert(5.5);
    listfloat.insert(2.3);
    listfloat.insert(9.8);
    listfloat.insert(7.1);
    cout << listfloat << endl;
    cout << listfloat[1] << endl;
    listfloat.remove(2);
    cout << listfloat << endl;
    listfloat.remove(100); 
}

