//
// Created by yang zhengtao on 2021/8/29.
//

#include <bits/stdc++.h>

using namespace std;

int main(){
    string str_s, str_a;

    getline(cin, str_s);
    getline(cin, str_a);

    vector<int> id_vec[26];
    int len_s = str_s.size(), len_a = str_a.size();
    for(int i = 0; i < len_s; ++i){
        id_vec[str_s[i] - 'a'].emplace_back(i);
    }

    int pre_ind = -1;
    int count = 0;
    for(char c : str_a){
        if(id_vec[c - 'a'].empty()){
            cout<<-1;
            return 0;
        }
        int pos = upper_bound(id_vec[c-'a'].begin(), id_vec[c-'a'].end(), pre_ind) - id_vec[c- 'a'].begin();

        int curr_ind = 0;
        if(pos < id_vec[c - 'a'].size()){
            curr_ind = id_vec[c - 'a'][pos];
        }
        else{
            curr_ind = id_vec[c - 'a'][0];
        }
        if(curr_ind <= pre_ind) ++count;
        pre_ind = curr_ind;
    }
    cout<<(long long)count * len_s + pre_ind + 1 - len_a<<endl;
    return 0;
}


