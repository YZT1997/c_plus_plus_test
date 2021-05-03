//
// Created by yang zhengtao on 2021/4/7.
//
#include "iostream"
#include "vector"

using namespace std;

int main(){
    int row, col, t;
    cin>>row>>col>>t;
    cin.ignore();

    vector<vector<int>> timeMap(row, vector<int>(col, 0)) ;
    for (int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j ){
            cin>>timeMap[i][j];
        }
        cin.ignore();
    }

    //
    vector<vector<int>> minTimeMap(row, vector<int>(col, 0));
    vector<vector<int>> maxTimeMap(row, vector<int>(col, 0));

    minTimeMap[0][0] = timeMap[0][0];
    maxTimeMap[0][0] = timeMap[0][0];

    // Init
    for (int i = 1; i < row; ++i) {
        minTimeMap[i][0] = timeMap[i][0] + minTimeMap[i - 1][0];
        maxTimeMap[i][0] = timeMap[i][0]+ maxTimeMap[i - 1][0];
    }
    for (int j = 1; j < col; ++j) {
        minTimeMap[0][j] = timeMap[0][j] + minTimeMap[0][j - 1];
        maxTimeMap[0][j] = timeMap[0][j] + maxTimeMap[0][j - 1];
    }

    // 最短时间
    for (int i = 1; i < row; ++i) {
        for(int j = 1; j < col; ++j ){
            minTimeMap[i][j] = timeMap[i][j] + min(minTimeMap[i - 1][j], minTimeMap[i][j - 1]);
            maxTimeMap[i][j] = timeMap[i][j] + max(minTimeMap[i - 1][j], maxTimeMap[i][j - 1]);
        }
    }
    int res = -1;
    if(t < minTimeMap[row - 1][col - 1]){
        cout<<-1;
        return -1;
    } else if (t > maxTimeMap[row - 1][col - 1]){
        cout<<maxTimeMap[row - 1][col - 1];
    }

    return 0;

}
