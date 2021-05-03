//
// Created by yang zhengtao on 2021/4/5.
//
#include <unordered_map>
#include <iostream>
#include <string>

const double pi = 3.14159;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    // 终止递归
    if(head == nullptr || head->next == nullptr) return nullptr;

    ListNode *nextPtr = head->next;
    head->next = swapPairs(nextPtr->next);
    nextPtr->next = head;

    return nextPtr;
}


int sum(int* ptrA, int* ptrB){
    int a = *ptrA;
    int b = *ptrB;
    return a + b;
}

void swapInd(int* ptrA, int* ptrB){
    int tmp;
    tmp = *ptrB;
    *ptrB = *ptrA;
    *ptrA = tmp;
}

using namespace std;
int main(){
    ListNode *head = new ListNode(10, nullptr);
    ListNode *firstHead = new ListNode(-1, head);

    for (int i = 0; i < 10; ++i) {
        head->next = new ListNode(2*i);
        head = head->next;
    }
    ListNode* resPtr = swapPairs(firstHead);

    while (resPtr != nullptr){
        cout<<resPtr->val<<endl;
        resPtr= resPtr->next;
    }
    return 0;
}
