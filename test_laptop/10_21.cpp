//
// Created by yang zhengtao on 2020/11/16.
//
#include "iostream"
#include "algorithm"
#include "functional"
#include "iterator"
#include "vector"
using namespace std;

class EvenByTwo{
private:
    int x;
public:
    EvenByTwo():x(0){}
    int operator()(){ return x += 2;}
};

int main(){
    int iarray1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int iarray2[] = {6, 6, 6, 7, 7, 7, 8, 9};
    vector<int> ivector1(iarray1, iarray1 + sizeof(iarray1) / sizeof(int ));
    vector<int> ivector2(iarray2, iarray2 + sizeof(iarray2) / sizeof(int ));
    vector<int> ivector3(2);
    ostream_iterator<int> output(cout, " ");

    //遍历ivector1, 每个加-1
    fill(ivector1.begin(), ivector1.end(), -1);
    copy(ivector1.begin(), ivector1.end(), output);
    cout<<endl;

    //遍历ivector1, 每个EvenByTwo
    generate(ivector1.begin(), ivector1.end(),EvenByTwo());
    copy(ivector1.begin(), ivector1.end(), output);
    cout<<endl;

    // 删除元素6后的ivector2, 置于另一个容器ivector2之中
    vector<int> ivector4;
    remove_copy(ivector2.begin(), ivector2.end(), back_inserter(ivector4), 6);
    copy(ivector4.begin(), ivector4.end(), output);
    cout<<endl;

    // 倒向重排
    reverse(ivector1.begin(), ivector1.end());
    copy(ivector1.begin(), ivector1.end(), output);
    cout<<endl;

    // 互换结果
    rotate(ivector1.begin(), ivector1.begin()+3, ivector1.end());
    copy(ivector1.begin(), ivector1.end(), output);
    cout<<endl;
    return 0;
}
