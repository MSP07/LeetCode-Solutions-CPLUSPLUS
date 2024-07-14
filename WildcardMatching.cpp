/*approach
  we start traversal from last index if we find same chars or one char and one '?' 
  we continue iteration if we encounter '*' we can either consider it empty and shrink i 
  to i-1 or take into all possible remaining string combos recursively so its either f(i-1,j)
  or f(i,j-1) and if we find differnet strings we can simply return false.
  when we get i<0 && j<0 means we have two empty strings so we return true
  if string2 is exhausted then it is false
  if string1 is exhausted and string2 is still there then it will be only true if the chars in 
  remaining string2 is  all '*' so we check for that.
  NOTE: we can implement in tabulation and space optimise too but in this question memoiztion
  gives us less runtime*/
class Solution{
private:
    bool find(string&p,int j){
        for(int k=0;k<=j;++k){
            if(p[j]!='*')return 0;
        }
        return 1;
    }
    bool fn(int i,int j,string&s,string&p,vector<vector<int>> &dp){
        if(i<0 && j<0)return 1;
        if(j<0)return 0;
        if(i<0)return find(p,j);
        if(dp[i][j]=-1)return dp[i][j];
        if(s[i]==p[j] || p[j]=='?')return dp[i][j] = fn(i-1,j-1,s,p,dp);
        if(p[j]=='*')return dp[i][j] = fn(i-1,j,s,p,dp) || fn(i,j-1,s,p,dp);
        return 0;
    }
public:
    bool isMatch(string s,string p){
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        return fn(n-1,m-1,s,p,dp);
    }
};
