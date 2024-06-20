/*approach
  if the total is odd we cannot parition into equal subsets so that is false
  then we run a function from 0 index to n-1 where we decrease or not decrease the target and
  the target is total/2. If with taking the current element it is possible to form partition we 
  return true else we return calling the same function without considering the current element 
  increasing the index and finding out. We use dp array memoization for this approach*/
class Solution{
private:
    bool isPossible(int ind,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(target==0)return true;
        if(target<0||ind>=nums.size())return false;
        if(dp[ind][target]!=-1)return dp[ind][target];
        if(isPossible(ind+1,nums,target-nums[ind],dp))return dp[ind][target] = true;
        return dp[ind][target] = isPossible(ind+1,nums,target,dp);
    }
public:
    bool canPartition(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int total = 0;
        for(int num:nums){
            total += num;
        }
        if(total%2)return false;
        int target = total/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        if(isPossible(0,nums,target,dp))return true;
        return false;
    }
};
