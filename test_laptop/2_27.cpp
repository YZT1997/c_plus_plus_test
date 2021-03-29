//
// Created by yang zhengtao on 2021/2/27.
//
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(){
    ListNode *l1;
    int i = 0;
    while (i<10){
        l1->val += i;
        l1 = l1->next;
        i++;
    }
    while (l1!= nullptr){
        std::cout<<l1->val;
        l1 = l1->next;
    }
    delete l1;

    return 0;
}


