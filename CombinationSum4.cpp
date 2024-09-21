/*approach
  dp take not take approach
  we start from first we take the num and reduce the target by that num
  if needed we can take a not take but it will overlook order of taking elements
  then we recursively call to find ways till the target becomes 0 if it does we return 1 indicating
  1 way is found else if target < 0 we return 0 indicating no way is possible, and finally return the ways
  we tabulate the same*/
class Solution{
private:
    int countWays(vector<int>& nums,int target,vector<int>& dp){
        if(target==0)return 1;
        if(target<0)return 0;
        if(dp[target]!=-1)return dp[target];
        int res = 0;
        for(int num:nums){
            res += countWays(nums,target-num,dp);
        }
        return dp[target] = res;
    }
public:
    int combinationSum4(vector<int>& nums,int target){
        vector<int>dp(target+1,0);
        dp[0] = 1;
        for(int i=0;i<=target;++i){
            for(int j=0;j<nums.size();++j){
                if(i>=nums[j]){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};
