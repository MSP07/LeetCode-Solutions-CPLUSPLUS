/*approach
  dp approach
  we initially take the char as extra so we add 1 to the dp[i] then we iterate throught the words in dictionary
  if the initial index + word's size is under string size and their substring gives us the word in dictionary
  then we have found a match and so we update dp[i] to min of dp[i] or dp[i+word.size()] hence ensuring removal
  of that word and finally return the ans at dp[0]*/
class Solution{
public:
    int minExtraChar(string s,vector<string>& dictionary){
        int n = s.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n] = 0;
        for(int i=n-1;i>=0;--i){
            dp[i] = 1 + dp[i+1];
            for(auto& word:dictionary){
                if(i+word.size()<=n && s.substr(i,word.size())==word){
                    dp[i] = min(dp[i],dp[i+word.size()]);
                }
            }
        }
        return dp[0];
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
