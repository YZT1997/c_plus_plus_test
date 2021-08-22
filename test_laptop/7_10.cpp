//
// Created by yang zhengtao on 2021/7/10.
//
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int a[20] ;
    int b = 1;
    memset(a, -2, sizeof(a));
    for(auto num : a){
        cout<<num<<" ";
    }
    return 0;
//

}
