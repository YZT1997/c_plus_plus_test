//
// Created by yang zhengtao on 2020/11/29.
//
#include "iostream"
#include "string"
using namespace std;

int main(){
    string line;
    cout<<"Type a line ended by 't' "<<endl;
    getline(cin, line, 't');
    cout<<line<<endl;
    return 0;
}
