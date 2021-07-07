#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

vector<string> res;

void print_queue(queue<int>& que){
    string str;
    while(!que.empty()){
        str += to_string(que.front());
        str += ' ';
        que.pop();
    }
    res.push_back(str);
}

void backtrack(queue<int> in, stack<int>st, queue<int>out, bool do_push){
    if(in.empty()){
        if(do_push) return;
        while(!st.empty()){
            out.push(st.top());
            st.pop();
        }
        print_queue(out);
        return;
    }
    else{
        if(do_push){
            st.push(in.front());
            in.pop();
        }
        else{
            if(st.empty()) return;
            out.push(st.top());
            st.pop();
        }
        backtrack(in, st, out, false);
        backtrack(in, st, out, true);
    }
}
int main(){
    int n, val;
    while(cin>>n){
        res.clear();
        queue<int> in, out;
        stack<int> st;
        while(n--){
            cin>>val;
            in.push(val);
        }
        backtrack(in, st, out, true);

        sort(res.begin(), res.end());
        for(auto row : res){
            cout<<row<<endl;
        }
    }
    return 0;
}