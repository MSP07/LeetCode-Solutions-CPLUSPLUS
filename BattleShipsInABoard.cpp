/*approach
  dfs approach
  we recursively check for boats/ships in the same row/column 
  if found so they are considered as one by this way we count the
  no of ships and finally return the no of ships*/
class Solution{
    vector<vector<int>>dirs={{-1,0},{1,0},{0,-1},{0,1}};
private:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || board[i][j]=='.')return;
        board[i][j] = '.';
        for(auto& dir:dirs){
            dfs(board,i+dir[0],j+dir[1]);
        }
    }
public:
    int countBattleships(vector<vector<char>>& board){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int ships = 0;
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[i].size();++j){
                ++ships;
                dfs(board,i,j);
            }
        }
        return ships;
    }
};
