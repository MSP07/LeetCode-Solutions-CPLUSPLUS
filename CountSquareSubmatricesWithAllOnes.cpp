/*approach
  dp approach
  goal is to find all 1's so when we encounter a 1 that is not on 1st row or 1st column side
  we check whether its top,left and top left are all 1 if so then min of all will be 1 and 1 + 1 will be 2
  indicating we found a 2x2 submatrix with all 1 but even if any one of them is 0 then min of them is 0 and 1 + 0 is 1
  indicating we only take that particular element as a 1x1 submatrix even for a 3x3 submatrix since we have updated the dp array
  if there is a 1 that can form 3x3 all its top,left and top left should be 2(from prev updation) so 1 + min(of all three) = 3
  like this we update and at the same time sum them up and finally return them giving us a 0(n square) time complexity and 0(n square) space complexity*/
class Solution{
public:
    int countSquares(vector<vector<int>>& matrix){
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int totalSquares = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(matrix[i][j]==1){
                    if(i==0 || j==0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    }
                    totalSquares += dp[i][j];
                }
            }
        }
        return totalSquares;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
