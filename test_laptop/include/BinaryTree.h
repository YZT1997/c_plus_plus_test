//
// Created by yang zhengtao on 2021/1/7.
//

#ifndef TEST_LAPTOP_BINARYTREE_H
#define TEST_LAPTOP_BINARYTREE_H
template <class T>
class BinaryTree{
private:
    struct Node{
        Node *left, *right;
        T data;

        Node():left(nullptr), right(nullptr){}
        Node(T item, Node *L = nullptr, Node *R = nullptr):data(item),left(L),right(R){}
        ~Node(){}
    };

    Node *root; // root Node of BinaryTree
public:
    BinaryTree():root(nullptr){}
    BinaryTree(T x){root = new Node(x);}
    BinaryTree(const Node *ptr){root = ptr;}
    ~BinaryTree(){clear();}
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T lChild(T x, T flag) const;
    T rChild(T x, T flag) const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void creatTree(T flag);
    T parent(T x, T flag) const {return flag;}

};

#endif //TEST_LAPTOP_BINARYTREE_H
