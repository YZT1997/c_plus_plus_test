//
// Created by yang zhengtao on 2020/10/19.
//
#include "iostream"
#include "LinkedList.h"

using  namespace std;

int main()
{
    cout<<"Enter 10 numbers"<<endl;            // Input 10 numbers
    LinkedList<int>list1 ;
    for (int i = 0; i < 10; ++i) {
        list1.insertRear(i+10);
    }

    list1.reset();
    list1.print();

    return 0;
}
