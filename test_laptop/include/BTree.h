//
// Created by yang zhengtao on 2021/1/7.
//

#ifndef TEST_LAPTOP_BTREE_H
#define TEST_LAPTOP_BTREE_H

template <class T>
class bTree{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root(T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T lChild(T x, T flag) const = 0;
    virtual T rChild(T x, T flag) const = 0;
    virtual void delLeft(T x) const = 0;
    virtual void delRight(T x) const = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;

};
#endif //TEST_LAPTOP_BTREE_H
