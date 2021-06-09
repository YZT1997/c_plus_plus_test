//
// Created by yang zhengtao on 2021/5/19.
//
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* merge(ListNode* l, ListNode* r){
    ListNode* head_res = new ListNode(0);
    ListNode* curr = head_res;
    cout<<curr->val<<" "<<head_res->next->val<<endl;

    while(l != nullptr && r != nullptr){
        if(l->val <= r->val){
            curr->next = l;
            curr = curr->next;
            l = l->next;
        }
        else{
            curr->next = r;
            curr = curr->next;
            r = r->next;
        }
    }

    if(l != nullptr){
        curr->next = l;
    }
    if(r != nullptr){
        curr->next = r;
    }
    cout<<curr->val<<" "<<head_res->next->val<<endl;
    return head_res->next;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> stack1;
    stack<int> stack2;

    while(l1 != nullptr){
        stack1.push(l1->val);
        l1 = l1->next;
    }

    while(l2 != nullptr){
        stack2.push(l2->val);
        l2 = l2->next;
    }

    int carry_sum = 0;      // 进位
    ListNode* head = nullptr;   // 返回的头部结点
    while(!stack1.empty() || !stack2.empty() || carry_sum > 0){
        int sum = carry_sum;
        if(!stack1.empty()){
            sum += stack1.top();
            stack1.pop();
        }
        if(!stack2.empty()){
            sum + stack2.top();
            stack2.pop();
        }
        ListNode* node = new ListNode(sum % 10);
        node->next = head;
        head = node;
        carry_sum = sum / 10;
    }
    return head;

}

int main(){
    ListNode *left = new ListNode(0);
    ListNode *left_head = left;
    ListNode *right = new ListNode(8);
    ListNode *right_head = right;
    for(int i = 0; i < 5; ++i){
        left->next = new ListNode(i + 1);
        left = left->next;
        right->next = new ListNode(10 + i);
        right = right->next;
    }


    int i = 1;
    cout<<++i;
    delete left, right, left_head, right_head;
    return 0;
}