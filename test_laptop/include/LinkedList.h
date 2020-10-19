//
// Created by yang zhengtao on 2020/10/19.
//

#ifndef TEST_LAPTOP_LINKEDLIST_H
#define TEST_LAPTOP_LINKEDLIST_H

#include "Node.h"
template <class T>
class LinkedList{
private:
    // Data member
    Node<T> *front, *rear;          // Start and end ptr
    Node<T> *prevPtr, *currPtr;     // Ptr recording current pos
    int size;                       // Size of current list
    int position;

    // Function member
    // Generate new node
    Node<T> *newNode(const T &item, Node<T> *ptrNext = nullptr);

    // Release node
    void freeNode(Node<T> *ptr);

    // Copy( assume the current list is empty)
    void copy(const LinkedList<T> &List);

public:
    LinkedList();                   // Constructor function
    LinkedList(const LinkedList<T> &List);  // Copy constructor function
    ~LinkedList();                          // Destructor function
    LinkedList<T> &operator = (const LinkedList<T> &List);

    int getSize() const;                    // Return the number of list
    bool isEmpty() const;                   // Whether the list is empty

    void reset(int pos = 0);                // Init the pos of handle
    void next();                            // Move the handle to next node
    bool endOfList() const;                 // whether the handle is in the end
    int currentPosition(void);              // Return the pos of handle

    void insertFront(const T &item);        // Insert a node
    void insertRear(const T &item);         // Insert a node at end
    void insertAt(const T &item);           // Insert a node before current
    void insertAfter(const T &item);        // Insert a node after current

    T deleteFront();                        // Delete node at start
    void deleteCurrent();                   // Delete current node

    T &data();                              // return quotation of current node data
    const T &data() const;                  // return constant quotation of current node data

    // Delete list
    void clear();
};

#endif //TEST_LAPTOP_LINKEDLIST_H
