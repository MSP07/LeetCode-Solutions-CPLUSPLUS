/*approach
  in the recursion relation we start from (0,0) and finish at last row that is n-1
  so the base case for dp will be dp[n-1][j] where we have to fill j as we dont know 
  which possible j could be part of min path so we take care of that first then when we
  run loop from 0 to i in the inner loop and we take the min path form dp[i+1][j](down)
  or dp[i+1][j+1] (down right) and we return the first element. In space optimisation we 
  do the same but with 1d array and simplified loops*/
class Solution{
public:
    int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        if(n==1)return triangle[0][0];
        //tabulation
        int m = triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;--i){
            for(int j=i;j>=0;--j){
                int down = triangle[i][j] + dp[i+1][j];
                int downr = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,downr);
            }
        }
        return dp[0][0];
        /*space optimization
        vector<int>dp(triangle.back());
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<=i;++j){
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];*/
    }
};
