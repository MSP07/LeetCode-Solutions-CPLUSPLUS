/*approach
  same as unique paths 1 we initialise dp array with dp[0][0] = 1 as base case in the function will be this
  then when we iterate if we come across obstacle we skip it by dp[i][j]=1
  else we increment the dp[i][j] accordingly as to whether i>0 or j>0 then we return the last element in the dp array*/
class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    if(i>0){
                        dp[i][j] += dp[i-1][j];
                    }
                    if(j>0){
                        dp[i][j] += dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
