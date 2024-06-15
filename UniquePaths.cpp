/*approach
  dynamic programming approach/tabulation
  we initially keep a vector all val as 1
  then start iterating from second element as dp[0][0]=1(if we start from last to first in matrix then the base case will be dp[0][0]=1)
  so the possible paths will be up(j-1) or left(i-1) so we add up their possible values to current[i][j] and finally return the last element*/
class Solution{
public:
    int uniquePaths(int m,int n){
        if(m==1 && n==1)return 1;
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
