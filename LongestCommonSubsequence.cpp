/*approach
  we iterate from last and when we reach the behind first index we return 0
  if we encounter same char then we increase the max count of subsequence by 1
  if not we choose the max od either [i-1][j] or [i][j-1]. we tabulate with this
  same approach too*/
class Solution{
private:
    int fn(int i,int j,string &text1,string &text2,vector<vector<int>> &dp){
        if(i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j])return dp[i][j] = 1 + fn(i-1,j-1,text1,text2,dp);
        return dp[i][j] = max(fn(i-1,j,text1,text2,dp),fn(i,j-1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1,string text2){
        int n = text1.size();
        int m = text2.size();
        //memoization
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        return fn(n-1,m-1,text1,text2,dp);
        //tabulation
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(text1[i-1]==text2[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
