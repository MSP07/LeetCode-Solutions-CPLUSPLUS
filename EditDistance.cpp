/*approach
  memoization
  we traverse from last till first if some char match we add nothing simply go before
  if they dont match then either we add a char which leads to j becoming j-1 or we
  delete the ith pointer char leading to i-1 or we replace which makes both i and j
  i-1 and j-1 each operation takes 1 cost/step so we return the min of all these three
  tabulation and space optimization can be done with this approach*/
class Solution{
private:
    int fn(int i,int j,string&word1,string&word2,vector<vector<int>> &dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])return dp[i][j] = fn(i-1,j-1,word1,word2,dp);
        return dp[i][j] = 1 + min(fn(i-1,j,word1,word2,dp),min(fn(i,j-1,word1,word2,dp),fn(i-1,j-1,word1,word2,dp)));
    }
public:
    int minDistance(string word1,string word2){
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        return fn(n-1,m-1,word1,word2,dp);
    }
};
