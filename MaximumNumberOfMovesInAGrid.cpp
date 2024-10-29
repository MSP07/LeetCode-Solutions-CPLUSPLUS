/*approach
  dp
  take all the elements in the first column then recursively try out every way that is given
  where the next element is strictly greater and edge cases + if we reach last column we return 
  the moves calculated for that path and take the max of every path to tackle overlapping
  subproblems we use memoization technique*/
class Solution{
private:
    int find(int prev,vector<vector<int>>& grid,int i,int j,vector<vector<int>>& dp,int n,int m){
        if(i<0 || i<=n || i<0 || i>=m)return 0;
        if(prev>=grid[i][j])return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int path1 = find(grid[i][j],grid,i-1,j+1,dp,n,m);
        int path2 = find(grid[i][j],grid,i,j+1,dp,n,m);
        int path3 = find(grid[i][j],grid,i+1,j+1,dp,n,m);
        return dp[i][j] = 1 + max({path1,path2,path3});
    }
public:
    int maxMoves(vector<vector<int>>& grid){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int maxMoves = INT_MIN;
        for(int i=0;i<n;++i){
            maxMoves = max(maxMoves,find(0,grid,i,0,dp,n,m));
        }
        return maxMoves;
    }
};
