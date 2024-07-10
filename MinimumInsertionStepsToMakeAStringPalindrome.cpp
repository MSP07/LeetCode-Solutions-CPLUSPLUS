/*approach
  we make use of longest palindromic subsequence
  as the min no of insertions will be the non palindromic 
  subsequence length. If there is a palindromic subsequence
  then we dont need to disturb it and the remaining is the 
  length we need to add as min insertions*/
class Solution{
public:
    int minInsertions(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = s.size();
        string r = s;
        reverse(r.begin(),r.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(s[i-1]==r[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n - dp[n][n];
    }
};
