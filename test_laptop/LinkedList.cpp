//
// Created by yang zhengtao on 2020/10/19.
//
#include "LinkedList.h"

// Get next node
template <class T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *ptrNext) {
    Node<T> *tempPtr = new Node<T>(item, ptrNext);
    return tempPtr;
}

// Free node
template <class T>
void LinkedList<T>::freeNode(Node<T> *ptr) {
    delete ptr;
}

// Constructor
template <class T>
LinkedList<T>::LinkedList()
{
    size = 0;
    front = rear = new Node<T>(0);
    currPtr = prevPtr = front;
}

// Get pos of current handle
template <class T>
int LinkedList<T>::currentPosition(void) {
    Node<T> *tempPtr = front->nextNode();
    position = 0;
    while (tempPtr != currPtr){
        tempPtr = tempPtr->nextNode();
        position++;
    }

    return position;
}

// Return size
template <class T>
int LinkedList<T>::getSize() const {
    return size;
}

// Return quotation of current node data
template <class T>
T &LinkedList<T>::data() {
    return currPtr->data;
}

// Return const quotation
template <class T>
const T&LinkedList<T>::data() const{
    return currPtr->data;
}

// move the handle to next node
template <class T>
void LinkedList<T>::next() {
    prevPtr = currPtr;
    currPtr = currPtr->nextNode();
}

//
template <class T>
bool LinkedList<T>::endOfList() const {
    if (currPtr == nullptr) return true;
    else return false;
}

// decide whether is empty
template <class T>
bool LinkedList<T>::isEmpty() const {
    if (front == rear) return true;
    else return false;
}

//reset, set the pos of first member is 0
template <class T>
void LinkedList<T>::reset(int pos) {
    prevPtr = front;
    currPtr = front->nextNode();
    position = pos;
    for (int i = 0; i < position; i++){
        prevPtr = currPtr;
        currPtr=currPtr->nextNode();
    }
}

// Insert node at start
template <class T>
void LinkedList<T>::insertFront(const T &item) {
    prevPtr = currPtr;
    currPtr = newNode(item, front->nextNode());
    front->next = currPtr;
    if (rear == front){
        rear = currPtr;
    }
    size++;
}

// Insert node at end
template <class T>
void LinkedList<T>::insertRear(const T &item) {
    prevPtr = currPtr;
    currPtr = newNode(item, rear->nextNode());
    rear->next = currPtr;
    rear = currPtr;
}

// Insert node after current
template <class T>
void LinkedList<T>::insertAfter(const T &item) {
    prevPtr = currPtr;
    Node<T> *tempPtr = newNode(item, currPtr->nextNode());
    currPtr->next = tempPtr;
    if (currPtr == rear){
        rear = tempPtr;
    }
    currPtr = tempPtr;
    size++;
}

// Insert node before current
template <class T>
void LinkedList<T>::insertAt(const T &item) {
    currPtr = newNode(item, prevPtr->nextNode());
    prevPtr->next = currPtr;
    size++;
}

// Delete head node
template <class T>
T LinkedList<T>::deleteFront() {
    currPtr = front->nextNode();
    delete front;
    front = currPtr;
    size--;
    return front->data;
}

// Delete current node
template <class T>
void LinkedList<T>::deleteCurrent() {
    Node<T> *tempPtr = currPtr;
    prevPtr->deleteAfter();
    delete currPtr;
    currPtr = prevPtr;
    size--;
}

// Clear
template <class T>
void LinkedList<T>::clear() {
    Node<T> *tempPtr = front->nextNode();
    while (tempPtr != nullptr){
        Node<T> *tempQ = tempPtr;
        tempPtr = tempPtr->nextNode();
        delete tempQ;
        size--;
    }
    rear = front;
    currPtr = prevPtr =front;
}

// Destructor
template <class T>
LinkedList<T>::~LinkedList<T>() {
    clear();
    delete front;
}