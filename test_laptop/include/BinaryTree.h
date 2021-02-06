//
// Created by yang zhengtao on 2021/1/7.
//

#ifndef TEST_LAPTOP_BINARYTREE_H
#define TEST_LAPTOP_BINARYTREE_H
#include "BTree.h"
#include "LinkQueue.h"

template<class T> class BinaryTree;
template<class T> void printTree(const BinaryTree<T> &t, T flag);

template <class T>
class BinaryTree{
    friend void printTree<T>(const BinaryTree &t, T flag);
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
    ~BinaryTree(){clear(root);}
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

private:
    Node *find(T x, Node *t) const;
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;

};

template<class T>
bool BinaryTree<T>::isEmpty() const {
    return root == nullptr;
}

template <class T>
T BinaryTree<T>::Root(T flag) const {
    if (root == nullptr) return flag;
    else return root->data;
}

template<class T>
void BinaryTree<T>::clear(Node *&t) {
    if (t == nullptr) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = nullptr;
}

template<class T>
void BinaryTree<T>::clear() {
    clear(root);
}

template<class T>
void BinaryTree<T>::preOrder(Node *t) const {
    if (t == nullptr) return;
    std::cout<<t->data<<' ';
    preOrder(t->left);
    preOrder(t->right);
}
template<class T>
void BinaryTree<T>::preOrder() const {
    std::cout<<"\n preOrder";
    preOrder(root);
}

template<class T>
void BinaryTree<T>::postOrder(Node *t) const {
    if (t == nullptr) return;
    postOrder(t->left);
    postOrder(t->right);
    std::cout<<t->data<<' ';
}
template<class T>
void BinaryTree<T>::postOrder() const {
    std::cout<<"\n postOrder";
    postOrder(root);
}

template<class T>
void BinaryTree<T>::midOrder(Node *t) const {
    if (t == nullptr) return;
    midOrder(t->left);
    std::cout<<t->data<<' ';
    midOrder(t->right);
}
template<class T>
void BinaryTree<T>::midOrder() const {
    std::cout<<"\n midOrder";
    midOrder(root);
}

template<class T>
void BinaryTree<T>::levelOrder() const {
    LinkQueue<Node*> que;
    Node *tmp;

    std::cout<<"\n leverOrder";
    que.enQueue(root);

    while (!que.isEmpty()){
        tmp = que.deQueue();
        std::cout<<tmp->data<<' ';
        if (tmp->left) que.enQueue(tmp->left);
        if (tmp->right) que.enQueue(tmp->right);
    }
}

template<class T>
typename BinaryTree<T>::Node *BinaryTree<T>::find(T x, BinaryTree<T>::Node *t) const {
    Node *tmp;
    if (t == nullptr) return nullptr;
    if (t->data == x) return t;
    if (tmp = find(x, t->left)) return tmp;
    else return find(x, t->right);
}

template<class T>
void BinaryTree<T>::delLeft(T x) {
    Node *tmp = find(x, root);
    if (tmp == nullptr) return;
    clear(tmp->left);
}

template<class T>
void BinaryTree<T>::delRight(T x) {
    Node *tmp = find(x, root);
    if (tmp == nullptr) return;
    clear(tmp->right);
}

template<class T>
T BinaryTree<T>::lChild(T x, T flag) const {
    Node *tmp = find(x, root);
    if (tmp == nullptr || tmp->left == nullptr) return flag;
    return tmp->left->data;
}

template<class T>
T BinaryTree<T>::rChild(T x, T flag) const {
    Node *tmp = find(x, root);
    if (tmp == nullptr || tmp->right == nullptr) return flag;
    return tmp->right->data;
}

template<class T>
void BinaryTree<T>::creatTree(T flag) {
    LinkQueue<Node*> que;
    Node *tmp;
    T x, lData, rData;
    std::cout<<"\n Please input the root node:";
    std::cin>>x;
    root = new Node(x);
    que.enQueue(root);
    while (!que.isEmpty()){
        tmp = que.deQueue();
        std::cout<<"\n Input "<<tmp->data<<" Two sons are";
        std::cin>>lData>>rData;
        if (lData != flag) que.enQueue(tmp->left = new Node(lData));
        if (rData != flag) que.enQueue(tmp->right = new Node(rData));
    }
    std::cout<<"\n completed! \n";
}


template<class T>
void printTree(const BinaryTree<T> &t, T flag){
    LinkQueue<T> q;
    q.enQueue(t.root->data);
    std::cout<<std::endl;
    while (!q.isEmpty()){
        char p, l, r;
        p = q.deQueue();
        l = t.lChild(p, flag);
        r = t.rChild(p, flag);
        std::cout<<p<<" "<<l<<" "<<r<<std::endl;
        if (l != flag) q.enQueue(l);
        if (r != flag) q.enQueue(r);
    }
}

#endif //TEST_LAPTOP_BINARYTREE_H
