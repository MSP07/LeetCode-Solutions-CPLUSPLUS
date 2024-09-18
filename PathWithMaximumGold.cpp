/*approach
  dfs, backtracking
  we start from a cell which is not 0 and find the highest sum we can take from that cell to
  each cell on in dfs we initially mark the cell visited by making it 0 as to prevent runtime error
  then we take the neighboring cells gold or sum that are greater than 0 and return the max from that
  with current cell gold value and we mark the cell unvisited by making the cell to its org value again*/
class Solution{
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
private:
    int dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        int gold = grid[i][j];
        grid[i][j] = 0;
        int maxSum = 0;
        for(auto& dir:dirs){
            int x = i + dir[0];
            int y = j + dir[1];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]>0){
                maxSum = max(maxSum,dfs(grid,x,y,n,m));
            }
        }
        grid[i][j] = gold;
        return maxSum + gold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        int maxSum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j] > 0){
                    maxSum = max(maxSum,dfs(grid,i,j,n,m));
                }
            }
        }
        return maxSum;
    }
};
