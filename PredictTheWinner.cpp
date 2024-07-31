/*approach
  dp - bottom up
  traverse keep track of max using game theory
  and finally return whether the last is positive
  element then p1 can atleast draw or win*/
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;++i){
            dp[i][i] = nums[i];
        }
        for(int k=2;k<=n;++k){
            for(int i=0;i<=n-k;++i){
                int j = i+k-1;
                dp[i][j] = max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};
