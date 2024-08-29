/*approach
  dfs
  first we iterate through the boundaries and turn all the land there to water and
  any other land connected to it to water. then we again iterate through whole matrix
  and if we see a land we call dfs again to calculate no of islands and return them finally*/
class Solution{
private:
    void dfs(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==1)return;
        grid[i][j] = 1;
        dfs(grid,i+1,j,n,m);
        dfs(grid,i-1,j,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i,j-1,n,m);
    }
public:
    int closedIsland(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int closedIslands = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if ((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==0){
                    dfs(grid,i,j,n,m);
                }
            }
        }

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;++j){
                if(grid[i][j]==0){
                    dfs(grid,i,j,n,m);
                    ++closedIslands;
                }
            }
        }
        return closedIslands;
    }
};
