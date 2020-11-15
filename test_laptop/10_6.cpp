//
// Created by yang zhengtao on 2020/11/15.
//
#include "list"
#include "iterator"
#include "string"
#include "iostream"
using namespace std;

int main(){
    string names1[] = {"a", "b", "c"};
    string names2[] = {"d", "e", "f"};
    list<string> s1 (names1, names1 + 3);
    list<string> s2 (names2, names2 + 3);

    //将s1的第一个放到s2的最后
    s2.splice(s2.end(),s1, s1.begin());
    list<string>::iterator iter1 = s1.begin();      // iter1 指向 s1首
    advance(iter1, 2);                        // iter1 前进2个元素
    list<string>::iterator iter2 = s2.begin();      //  iter2 指向 s2首
    ++iter2;                                        //  前进1个元素
    list<string>::iterator iter3 = iter2;
    advance(iter3, 1);

    // 将[iter2, iter3）范围内的节点接到 s1中iter1指向的节点前
//    s1.splice(iter1, s2, iter2, iter3);
    s1.splice(iter1, s2);

    //分别将s1, s2输出
    cout<<"s1 is ";
    copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
    cout<<endl<<"s2 is ";
    copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
    cout<<endl;

    return 0;
}