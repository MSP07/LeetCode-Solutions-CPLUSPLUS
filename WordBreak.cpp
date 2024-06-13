/*approach
  initalise a dp array with everything as 0 (false). 
  push the given wordDict inside set to iterate through it
  and if we find the sunstring in the set then we change it to 1, then break
  we return the last before element in the dp array*/
class Solution{
public:
    bool wordBreak(string s,vector<string>& wordDict){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = s.length();
        vector<int>dp(n+1,0);
        unordered_set<string>wordCnt(wordDict.begin(),wordDict.end());
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&wordCnt.find(s.substr(j,j-i+1))!=wordCnt.end()){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
