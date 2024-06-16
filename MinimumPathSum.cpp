/*approach
  dp approach when we come to first element dp[0][0] we make it as grid[0][0] as this will be the base case
  since our approach reaches [0][0] we start from [m-1][n-1] so we move up or left
  when we move out of grid i<0 or j<0 we make that path infusible by adding INT_MAX since our question is to find min
  then we find up and left and take the min val of both for dp array and return the final element in the dp array since
  the answer will be stored there*/
class Solution{
public:
    int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up += INT_MAX;
                    int left = grid[i][j];
                    if(j>0) left += dp[i][j-1];
                    else left += INT_MAX;
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
