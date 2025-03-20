/*approach
  dp, memoization
  we try out all the possible chars adding in order of given s1 and s2
  if we reach the ends of them successfully we return true else we return false
  since there can be overlapping subproblems we use memoization*/
class Solution {
private:
    bool solve(int i,int j,string& s1,string& s2,string& s3,vector<vector<int>>& dp){
        if(i==s1.size() && j==s2.size())return true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i<s1.size() && s1[i]==s3[i+j]){
            if(solve(i+1,j,s1,s2,s3,dp))return dp[i][j] = true;
        }
        if(j<s2.size() && s2[j]==s3[i+j]){
            if(solve(i,j+1,s1,s2,s3,dp))return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};
