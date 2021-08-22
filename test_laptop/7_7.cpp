#include<iostream>
#include<vector>
#include <algorithm>
#include<map>

using namespace std;

bool my_compare(const pair<int, int>& a, const pair<int, int>& b){
    return a.second > b.second || a.second == b.second && a.first < b.first;
}

int main(){
    int n;
    cin>>n;

    int sla = 0, score = 0;
    vector<pair<int, int>> vec;
    long int res = 0;
    vector<int> list_order;

    for(int i = 0; i < n; ++i){
        cin>>sla>>score;
        vec.push_back({sla, score});
        list_order.push_back(0);
    }

    //
    sort(vec.begin(), vec.end(), my_compare);

    int start_time = -1;
    for(int i = 0; i < n; ++i){
        int temp_order = vec[i].first - 1;

        while (temp_order > start_time){
            if(list_order[temp_order] == 0){
                list_order[temp_order] = 1;
                res += vec[i].second;
                break;
            }
            temp_order--;
        }
        if(temp_order == start_time ) start_time = vec[i].first - 1;
    }
    cout<<res<<endl;
    return 0;

}

/*
int main(){
    int n;
    cin>>n;

    int sla = 0, score = 0;
    map<int, vector<int>> work_list;
    while(n--){
        cin>>sla>>score;
        work_list[sla].push_back(score);
    }

    int res = 0, start_time = 0;
    for(auto iter = work_list.begin(); iter != work_list.end(); iter++){
        sla = iter->first;
        sort(iter->second.rbegin(), iter->second.rend());
        for(int i = 0; i < sla - start_time; ++i){
            res += iter->second[i];
        }
        start_time = sla;
    }

    cout<<res<<endl;
    return 0;

}
 */