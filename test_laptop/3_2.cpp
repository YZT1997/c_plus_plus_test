#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int getMaxStep(string& strBig, string& strSmall, int ind);
int main(){
    string strBig, strSmall;
    string strInd;
    int ind = 0;

    getline(cin, strBig);
    getline(cin, strSmall);
    getline(cin,strInd);

    ind = std::stol(strInd);

    int res = getMaxStep(strBig, strSmall, ind);
    cout<<res;
    return 0;

}
int getMaxStep(string& strBig, string& strSmall, int ind){
    unordered_map<char, int> need, window;
    for(char c:strSmall) need[c]++;

    int left = ind, right = ind;
    int valid= 0;

    int step = 0;
    while (right < strBig.size()){
        char c = strBig[right];
        right++;
        // update
        if (need.count(c)){
            cout<<need.count(c)<<endl;
            window[c]++;
            if(window[c] == need[c]){
                valid++;
            }
        }
        // left window
        while (right - left >= strSmall.size()){
            // judge
            if(valid == need.size()){
                break;
            }
            char d = strBig[left];
            left++;
            if(need.count(d)){
                if(window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    step = right - 1;
    return step;
}