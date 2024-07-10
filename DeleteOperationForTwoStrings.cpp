/*approach
  we need to find no of operations/deletions to be performed
  to find the lca. So if we find the length of lca and subtract it
  from the length of the string then we get the required deletions 
  for that particular string so we find for both strings and sum them*/
class Solution{
public:
    int minDistance(string word1,string word2){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int lcs = dp[n][m];
        return (n-lcs) + (m-lcs);
    }
};
