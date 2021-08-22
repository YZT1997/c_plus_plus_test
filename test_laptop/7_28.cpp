//
// Created by yang zhengtao on 2021/7/28.
//
#include <iostream>
#include <unordered_map>


using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> ch2str;
    unordered_map<string, char> str2ch;
    int len_str = s.size();
    int i = 0;

    for(auto c : pattern){
        if(i > len_str){
            return false;
        }
        int j = i;
        while(j < len_str && s[j] != ' ')j++;
        const string temp_str = s.substr(i, j - i);
        if(ch2str.count(c) && ch2str[c] != temp_str){
            return false;
        }
        if(str2ch.count(temp_str) && str2ch[temp_str] != c){
            return false;
        }
        ch2str[c] = temp_str;
        str2ch[temp_str] = c;
        i = j + 1;
    }

    return i >= len_str;

}

int main(){
    string pattern = "abba", str = "cat dog dog cat";
    bool is_res = wordPattern(pattern, str);
    cout<<is_res<<endl;

    return 0;
}
