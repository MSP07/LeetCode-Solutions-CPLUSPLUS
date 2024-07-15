/*approach
  if we encounter a 1 we increase the cnt by one and call dfs function
  which will recursively call the cells in all four direction and the base
  case will be edge cases and if the grid is not '1' then we return back
  this ensures that whichever 1 is connected to the 1 we call is either marked
  or changed with one cnt and finally we return the cnt*/
class Solution{
private:
    void dfs(vector<vector<char>> &grid,int n,int m,int i,int j){
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j] != '1')return;
        grid[i][j] = 0;
        dfs(grid,n,m,i+1,j);
        dfs(grid,n,m,i-1,j);
        dfs(grid,n,m,i,j+1);
        dfs(grid,n,m,i,j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,n,m,i,j);
                }
            }
        }
        return cnt;
    }
};
