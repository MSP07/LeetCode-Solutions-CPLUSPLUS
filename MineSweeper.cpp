/*approach
  we start by checking whether the starting cell is a 'X' if so we change that cell alone and return the board
  else we use dfs approach to calculate mines surrounding the staring cell if there are mines then we change the cell to
  minesCount else we look for neighbors by recursively calling dfs and change the cells accordingly and return the board finally*/
class Solution{
    vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
private:
    int countAdj(vector<vector<char>>& board,int row,int col,int n,int m){
        int cnt = 0;
        for(auto& dir:dirs){
            int newR = row + dir[0];
            int newC = col + dir[1];
            if(newR>=0 && newC>=0 && newR<n && newC<m && board[newR][newC] == 'M'){
                ++cnt;
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& board,int row,int col,int n,int m){
        int mineCount = countAdj(board,row,col,n,m);
        if(mineCount>0){
            board[row][col] = mineCount + '0';
        }else{
            board[row][col] = 'B';
            for(auto& dir:dirs){
                int newR = row + dir[0];
                int newC = col + dir[1];
                if(newR>=0 && newC>=0 && newR<n && newC<m && board[newR][newC] == 'E'){
                    dfs(board,row,col,n,m);
                }
            }
        }
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board,vector<int>& click){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int row = click[0];
        int col = click[1];
        int n = board.size();
        int m = board[0].size();

        if(board[row][col] == 'M'){
            board[row][col] = 'X';
            return board;
        }

        dfs(board,row,col,n,m);

        return board;
    }
};
