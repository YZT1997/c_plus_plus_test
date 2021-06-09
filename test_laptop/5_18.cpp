//
// Created by yang zhengtao on 2021/5/18.
//
#include <iostream>

template<typename T>
bool compareMy(const T a, const T b){
    return a > b;
}

using namespace std;
class Father{
public:
    virtual void func(int i = 0){
        std::cout<<"Father "<<i<<"\n";
    }
};

class Son: public Father{
public:
    void func(int i = 1){
        std::cout<<"Son "<<i<<"\n";
    }
};

void test(){
    Son* ptrSon = new Son();
    Father* ptrFather = ptrSon;
    ptrSon->func();
    ptrFather->func();
    delete ptrSon;
}

void test(int &a){
    a = a + 10;
}
int main(){
    int a = 5;
    test(a);
    cout<<a;
    return 0;

}
