//
// Created by yang zhengtao on 2021/4/22.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

class Fish{
public:
    explicit Fish(){
        std::cout<<"Construct Fish"<<std::endl;
    }
    virtual void Swim(){
        std::cout<<"Fish"<<std::endl;
    }
};

class Tuna : public Fish{
public:
    explicit Tuna(){
        std::cout<<"Construct Tuna"<<std::endl;
    }
    void Swim(){
        std::cout<<"Tuna"<<std::endl;
    }
};

void MakeFishSwim(Fish& inputFish){
    inputFish.Swim();
}
bool compare(const int& a, const int& b){
    std::string str_a = std::to_string(a);
    std::string str_b = std::to_string(b);
    return std::stoi(str_a + str_b) > std::stoi(str_b + str_a);
}
using namespace std;
int main(){
    stack<char> s;
    s.push('c');
    cout<<s.top();

    return 0;
}
