/*approach
  dp - take,notTake
  we start from first index and take count of zeroes and ones and if they are below the m and n
  we take that string and update new m and n. we simply skip the curr index and make it notTake
  so as to try all subsequences and return the max out of them both. since this can cause overlapping subproblems
  we memoize it and tabulate this same approach*/
class Solution{
private:
    int find(int i,vector<string>& strs,int m,int n,vector<vector<vector<int>>>& dp){
        if(i>=strs.size())return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int zero = 0, ones = 0;
        for(char c:strs[i]){
            if(c=='0')zero++;
            if(c=='1')ones++;
        }
        int take = 0;
        if(zero<=m && ones<=n){
            take = 1 + find(i+1,strs,m-zero,n-ones,dp);
        }
        int notTake = find(i+1,strs,m,n,dp);
        return dp[i][m][n] = max(take,notTake);
    }
public:
    int findMaxForm(vector<string>& strs,int m,int n){
        //memoization approach
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return find(0,strs,m,n,dp);
        //tabulation approach
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(const string& str:strs){
            int zero = 0, ones = 0;
            for(char c:str){
                if(c=='0')zero++;
                if(c=='1')ones++;
            }
            for(int i=m;i>=zero;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j] = max(dp[i][j],1+dp[i-zero][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};
