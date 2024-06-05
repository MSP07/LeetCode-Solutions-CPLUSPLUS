//approach
//we keep cols and diagonals vectors
//if there are no primary or secondary diagonals attack in the position we place Q there and make it true
//we recursively call it for next row and while backtracking meaning before calling the function one more time we again make it '.' or to its previous value
class Solution{
private:
    vector<vector<string>>result;
    void solve(int row,int n,vector<string>&board,vector<bool>&cols,vector<bool>&diag1,vector<bool>&diag2){
        if(row==n){
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (!cols[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
                board[row][col] = 'Q';
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
                solve(row + 1, n, board, cols, diag1, diag2);
                board[row][col] = '.';
                cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<string>board(n,string(n,'.'));
        vector<bool>cols(n,false);
        vector<bool>diag1(2*n-1,false);
        vector<bool>diag2(2*n-1,false);
        solve(0,n,board,cols,diag1,diag2);
        return result;
    }
};
