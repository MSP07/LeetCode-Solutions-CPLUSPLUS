/*approach
  dp,dfs approach
  we calculate lis from each cell of the grid and since this process can cause
  overlapping subproblems we store the seen/previous values in dp array
  and return the already visited cells in the matrix
*/
class Solution{
    vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
private:
    int find(vector<vector<int>>& matrix,int i,int j,int n,int m,vector<vector<int>>& dp){
        if(dp[i][j] != -1)return dp[i][j];
        int maxLen = 1;
        for(auto& dir:dirs){
            int x = i + dir[0];
            int y = j + dir[1];
            if(x>=0 && y>=0 && x<n && y<m && matrix[x][y] > matrix[i][j]){
                maxLen = max(maxLen,1+find(matrix,x,y,n,m,dp));
            }
        }
        return dp[i][j] = maxLen;
    }
public:
    int longestIncreasingSubsequence(vector<vector<int>>& matrix){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxLen = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                maxLen = max(maxLen,find(matrix,i,j,n,m,dp));
            }
        }
        return maxLen;
    }
};
