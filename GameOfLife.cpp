/*approach
  matrix, simulation
  to prevent using another matrix what we do is
  first we calculate the no of lives in neighborhood and modify matrix element to -1
  if that cell is inhabitable and if habitable change it to 2 we change to -1 as 1 val is
  preserved for other neighborhoods we can simply choose the condition abs(matrix[i][j])==1?
  then we iterate once again and change -1 values to 0 and 2 values to 1 and return the matrix again*/
class Solution{
    vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
private:
    int countLives(vector<vector<int>>& board,int i,int j,int n,int m){
        int count = 0;
        for(auto& dir:dirs){
            int x = i + dir[0];
            int y = j + dir[1];
            if(x>=0 && x<n && y>=0 && y<m && abs(board[x][y])==1){
                ++count;
            }
        }
        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board){
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int live = countLives(board,i,j,n,m);
                if(board[i][j]==1 && (live<2 || live>3)){
                    board[i][j] = -1;
                }else if(board[i][j]==0 && live==3){
                    board[i][j] = 2;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==-1)board[i][j] = 0;
                if(board[i][j]==2)board[i][j] = 1;
            }
        }
    }
};
