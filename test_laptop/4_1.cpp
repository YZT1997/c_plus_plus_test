#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include "unordered_map"

struct Coord{
    int x, y;
    Coord(int x, int y):x(x),y(y){};
};

using namespace std;
int indexSearch(string& str);
int Max(int index, int index2){
    return (index>index2)? index:index2;
}

int main(){
    ifstream in;
    in.open("../test.txt", ios::in);
    if (!in.is_open()){
        cout<<"Failed"<<endl;
        return -1;
    }

    vector<pair<double, double>> vec;
    vector<pair<string, string>> vecStr;
    vector<string> vecRaw;

    string s;
    while (getline(in, s, '\n')){
//        if (s == "" || s == " ") continue;      // 去除空格与空行的影响
//        int ind = indexSearch(s);
//        string strFront = s.substr(0, ind);
//        string strBack = s.substr(ind+1, s.length());
//        double x = stod(strFront);
//        double y = stod(strBack);
//        pair<double, double> p(x, y);
//        pair<string, string> pStr(strFront, strBack);
//        vec.push_back(p);
//        vecStr.push_back(pStr);
        vecRaw.push_back(s);
    }

//    while (!vecStr.empty()){
//        cout<<vecStr[0].first<<" "<<vecStr[0].second<<endl;
//        vecStr.erase(vecStr.begin());
//    }
//    while (!vec.empty()){
//        cout<<vec[0].first<<" "<<vec[0].second<<endl;
//        vec.erase(vec.begin());
//    }
    int count[26] = {0};
    for (int i = 0; i < 26; ++i) {
        cout<<count[i]++<<" ";

    }
    return 0;
}



int indexSearch(string& str){
    int len = str.length();
    int res = -1;
    for (int i = 0; i < len; ++i) {
        char c = str[i];
        if (c == ','){
            res = i;
            break;
        }
    }
    return res;
}