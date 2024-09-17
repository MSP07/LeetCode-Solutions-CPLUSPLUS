/*approach
  we start from 0th index go on till last before index
  we default take the char at the index if at any point s[i] = '0' we return 0
  else if we can successfully iterate entire string we return 1
  we check for the possibiility of taking two chars and passs two indices at the same time and
  we add that ways to ans and return it finally*/
class Solution{
private:
    int findWays(int i,string&s,vector<int>& dp,int n){
        if(i==n)return 1;
        if(s[i]=='0')return 0;
        if(dp[i]!=-1)return dp[i];
        int ways = findWays(i+1,s,dp,n);
        if(i<n-1 && s.substr(i,2) < "27"){
            ways += findWays(i+2,s,dp,n);
        }
        return dp[i] = ways;
    }
public:
    int numDecodings(string s){
        int n = s.size();
        vector<int>dp(n+1,0);
        return findWays(0,s,dp,n);
    }
};
