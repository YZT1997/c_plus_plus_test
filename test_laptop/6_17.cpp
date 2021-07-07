#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec(9, vector<int>(9, 0));

bool isValid(int row, int col, int val){
    for(int i = 0; i < 9; ++i){
        if(vec[row][i] == val || vec[i][col] == val || vec[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == val) return false;
    }
    return true;
}

bool dfs(int row, int col){
    if(row == 9) return true;
    if(col == 9) return dfs(row + 1, 0);

    for(int i = row; i < 9; ++i){
        for(int j = col; j < 9; ++j){
            if(vec[i][j] != 0) return dfs(i, j + 1);
            for(int k = 1; k <= 9; ++k){
                if(!isValid(i, j, k)) continue;
                vec[i][j] = k;
                if (dfs(i, j + 1)) return true;
                vec[i][j] = 0;
            }
            return false;
        }
    }
    return false;

}


int main(){
    int val = 0;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cin>>val;
            vec[i][j] = val;
        }
    }

    bool is_sudoku = false;
    is_sudoku = dfs(0, 0);
    if(!is_sudoku) return -1;

    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}