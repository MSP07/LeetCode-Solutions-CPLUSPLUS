/*approach
  dp
  we first add 1 to first and last and iterate from 1 to n-2
  since i and j will be pointing to 1 and n-2 we need to calculate
  nums[i-1]*nums[ind]*nums[j+1] as calculating from last element whichever
  remains will be easy as 1*last el*1 and then we expand so we do this approach
  we memoize and tabulate this too*/
class Solution {
private:
    int fn(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi = INT_MIN;
        for(int ind=i;ind<=j;++ind){
            long long cost = nums[i-1]*nums[ind]*nums[j+1] + fn(i,ind-1,nums,dp) + fn(ind+1,j,nums,dp);
            if(cost > maxi){
                maxi = cost;
            }
        }
        return dp[i][j] =  maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int i=nums.size()-2;i>=1;--i){
            for(int j=i;j<=nums.size()-2;++j){
                if(i>j)continue;
                int maxi = INT_MIN;
                for(int ind=i;ind<=j;++ind){
                    long long cost = nums[i-1]*nums[ind]*nums[j+1] + dp[i][ind-1]+ dp[ind+1][j];
                    if(cost > maxi){
                        maxi = cost;
                    }
                }
                dp[i][j] =  maxi;
            }
        }
        return dp[1][nums.size()-2];
    }
};
