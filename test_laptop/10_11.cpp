//
// Created by yang zhengtao on 2020/11/15.
//
#include "iostream"
#include "map"
#include "cctype"
using namespace std;

int main(){
    map<char, int> s;
    char c;
    do {
        cin>>c;
        if (isalpha(c)){        // judge whether it is alpha
            c = tolower(c);
            s[c]++;             // 将该字母出现频率加1
        }
    }while (c != '.');

    // output count of each alpha
    for (map<char, int>::iterator iter = s.begin(); iter != s.end(); ++iter){
        cout<<iter->first<<" "<<iter->second<<" ";
    }
    cout<<endl;
    return 0;
}