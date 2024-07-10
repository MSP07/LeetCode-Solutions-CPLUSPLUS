/*approach
  we make use of longest common subsequence approach
  if we reverse the given string the palindrome should
  still be same so if we find the lca of the given string
  and its reversed one then we will get the answer*/
class Solution{
private:
    int fn(int i,int j,string&s,string&r,vector<vector<int>> &dp){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==r[j]){
            return dp[i][j] = 1 + fn(i-1,j-1,s,r,dp);
        }
        return dp[i][j] = max(fn(i-1,j,s,r,dp),fn(i,j-1,s,r,dp));
    }
public:
    int longestPalindromicSubseq(string s){
        int n = s.size();
        string r =s;
        reverse(r.begin(),r.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return fn(n-1,n-1,s,r,dp);
    }
};
