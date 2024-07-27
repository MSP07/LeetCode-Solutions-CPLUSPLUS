/*approach
  dp approach
  we keep another vector cnt to count no of time the subsequence of
  same length ocuured. when we encounter normal increasing subsequence
  and it is new that is dp[i] < dp[j] + 1 we are encountering that 
  particular subsequence for the first time. so we simply inherit the
  cnt[j] to that element (cnt[i] = cnt[j]). but if the sequence's length
  is already met that is dp[i] = dp[j] + 1 then we increase the cnt of that
  element by prev elements count(cnt[i] += cnt[j]). we keep track of max element
  as that is the length of the lis and we iterate through cnt at the end to find
  cnt of how much lis's are there in the given list and add them and return it*/
class Solution{
public:
    int findNumberOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n,1), cnt(n,1);
        int maxi = 1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }else if(nums[j] < nums[i] && dp[i] == dp[j] + 1){
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int lis = 0;
        for(int i=0;i<n;++i){
            if(maxi == dp[i])lis += cnt[i];
        }
        return lis;
    }
};
