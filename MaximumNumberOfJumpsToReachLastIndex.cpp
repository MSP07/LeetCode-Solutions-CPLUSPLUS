/*approach
  dp approach
  we start from first index and iterate through all the possibilities with another pointer from ind+1 to last
  if the elements on the two pointers satisfy the conditions then we take it and we update the maxJumps.  
  We memoize and tabulate this approach*/
class Solution{
private:
    int maxJumpsFinder(int ind,vector<int>& nums,int target,vector<int>& dp){
        if(ind==nums.size()-1)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int maxJumps = -1;
        for(int j=ind+1;j<nums.size();++j){
            if(-target<=nums[j]-nums[ind] && nums[j]-nums[ind]<=target){
                int take = maxJumpsFinder(j,nums,target,dp);
                if(take != -1){
                    maxJumps = max(maxJumps,1+take);
                }
            }
        }
        return dp[ind] = maxJumps;
    }
public:
    int maximumJumps(vector<int>& nums,int target){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int>dp(nums.size()+1,-1);
        dp[nums.size()-1] = 0;
        for(int ind=nums.size()-2;ind>=0;ind--){
            for(int j=ind+1;j<nums.size();++j){
                if(dp[j]!=-1){
                    dp[ind] = max(dp[ind],1+dp[j]);
                }
            }
        }
        return dp[0];
    }
};
