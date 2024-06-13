/*approach
  declare a vector dp of size n
  initially dp[0] is the first house and dp[1] will be the max of the first house and second house
  then dp[i] will be either previous one (dp[i-1]) or the sum of house before the prev one and the current one whichever is maximum
  we finally return the dp[n-1] since it is 0 based indexing*/
class Solution{
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n);
        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
