/*approach
  dp
  we start from first index and if we find a palindrome 
  of any substring we simply add 1 and check whether there
  are any other palindromes or the next whole substrings can
  be divided into palindromes and we return the min of that*/
class Solution{
private:
    bool isPalindrome(string&s,int start,int end){
        while(start<end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    int fn(string&s,int i,vector<int>& dp){
        if(i==s.size())return -1;
        if(dp[i] != -1)return dp[i];
        int mini = INT_MAX;
        for(int j=i;j<s.size();++j){
            if(isPalindrome(s,i,j)){
                int cut = 1 + fn(s,j+1,dp);
                mini = min(mini,cut);
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s){
        int n = s.size();
        vector<int>dp(n+1,-1);
        for(int i=s.size()-1;i>=0;i--){
            int mini = INT_MAX;
            for(int j=i;j<s.size();++j){
                if(isPalindrome(s,i,j)){
                    int cut = 1 + dp[j+1];
                    mini = min(mini,cut);
                }
            }
            dp[i] = mini;
        }
        return dp[0];
    }
};
