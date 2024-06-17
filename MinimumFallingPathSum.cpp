/*approach
  dp tabulation approach the base case will be at dp[n-1][j] we have to fill [j]
  then start from matrix[n-2][0] we calculate paths that are down[i+1][j], downl[i+1][j-1]
  downr[i+1][j+1] for downl and downr we check for edge cases and add there paths if out of boundary
  we neglect the path by adding a huge value to them. Then we update dp[i][j] with matrix[i][j] and  
  min value of those three. Now the answer is stored in the first row to find out that we find the lowest
  element in the first row of dp*/
class Solution{
public:
    int minFallingPathSum(vector<vector<int>>& matrix){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = matrix.size();
        if(n==1)return matrix[0][0];
        vector<vector<int>>dp(n,vector<int>(n));
        for(int j=0;j<n;++j){
            dp[n-1][j] = matrix[n-1][j];
        }
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<n;++j){
                int down = dp[i+1][j];
                int downl = (j>0)? dp[i+1][j-1] : INT_MAX;
                int downr = (j<n-1)? dp[i+1][j+1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min({down,downl,downr});
            }
        }
        int result = INT_MAX;
        for(int j=0;;j<n;j++){
            result = min(result,dp[0][j]);
        }
        return result;
    }
};
