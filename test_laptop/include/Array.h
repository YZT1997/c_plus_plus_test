//
// Created by yang zhengtao on 2020/10/18.
//

#ifndef TEST_LAPTOP_ARRAY_H
#define TEST_LAPTOP_ARRAY_H
# include "cassert"

// array class template
template<class T>
class Array {
private:
    T *list;
    int size;
public:
    Array(int size = 50);       // Constructor function
    Array(const Array<T> &a);   // Copy constructor function
    ~Array();                   // Destructor function
    Array<T> &operator = (const Array<T> &rhs);     // Reload "=" make class array could be assigned all
    T &operator [] (int i);                   // Reload []
    const T & operator [] (int i) const;
    operator T *();
    operator const T *() const;
    int getSize() const;
    void resize(int size);
};

// Constructor function
template <class T>
Array<T>::Array(int sizeInput) {
    assert(sizeInput > 0);
    size = sizeInput;
    list = new T [size];        //dynamic assign number = size (Type T)
}

// Destructor function
template <class T>
Array<T>::~Array<T>() {
    delete [] list;
}

// Copy constructor Function
template <class T>
Array<T>::Array(const Array<T> &a) {
    size = a.size;          // get the size of original a
    list = new T [size];    // call for memory and check
    for (int i = 0; i < size; i++) {
        list[i] = a.list[i];
    }                       // copy item
}

// reload "="
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs) {
    if (&rhs != this){
        // compare the size
        if (size != rhs.size){
            delete [] list;         // delete original list
            size = rhs.size;        // set the size of list
            list = new T[size];     // reassign memory
        }

        // copy
        for (int i = 0; i < size; ++i) {
            list[i] = rhs.list[i];
        }
    }
    return *this;                   // return current class
}

// reload [] operator
template <class T>
T &Array<T>::operator[](int i) {
    assert(i >= 0 && i < size);
    return list[i];
}

template <class T>
const T &Array<T>::operator[](int i) const {
    assert(i >= 0 && i < size);
    return list[i];
}

// Reload "*" operator
template <class T>
Array<T>::operator T*(){
    return list;
}

template <class T>
Array<T>::operator const T*() const{
    return list;
}

// Get size of current array
template <class T>
int Array<T>::getSize() const {
    return size;
}

// Change the size of array to newSize
template <class T>
void Array<T>::resize(int newSize) {
    assert(newSize > 0);
    if (newSize == size){
        return;
    }
    T *newList = new T[newSize];
    int n = (newSize < size)?newSize:size;

    // trans
    for (int i = 0; i < n; i++) {
        newList[i] = list[i];
    }
    delete[] list;
    list = newList;
    size = newSize;
}

#endif //TEST_LAPTOP_ARRAY_H
