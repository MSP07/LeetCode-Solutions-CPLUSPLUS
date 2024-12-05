/*approach
  dp
  we try all paths and take the min one from last to first bottom up
  to make sure hp stays positive whenever the health becomes <= 0 i make
  the hp 1 and continue to find the min and seperate the dungeon[i][j] from it
  and return the final value*/
class Solution{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon){
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        dp[n][m-1]=1;
        dp[n-1][m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int health = min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                dp[i][j] = health<=0 ? 1 : health;
            }
        }
        return dp[0][0];
    }
};
