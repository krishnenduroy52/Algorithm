#include<iostream>
#include<vector>
using namespace std;

void findSolution(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &left, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int row = 0; row < n; ++row){
        if(!left[row] && !upperDiagonal[row + col] && !lowerDiagonal[n-1 + col - row]){
            board[row][col] = 'Q';
            left[row] = 1;
            upperDiagonal[row + col] = 1;
            lowerDiagonal[n-1 + col - row] = 1;
            findSolution(col + 1, board, ans, left, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            left[row] = 0;
            upperDiagonal[row + col] = 0;
            lowerDiagonal[n-1 + col - row] = 0;                                
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board (n);
    string s (n, '.');
    for(int i = 0; i < n; i++)
        board[i] = s;
    
    vector<vector<string>> ans;
    vector<int> left(n, 0), upperDiagonal(2*n -1), lowerDiagonal(2*n - 1);
    findSolution(0, board, ans, left, upperDiagonal, lowerDiagonal, n);
    return ans;
}

int main(){
    int n; 
    cin>> n;
    vector<vector<string>> ans = solveNQueens(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}