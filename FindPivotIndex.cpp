/*approach
  prefixSum
  we can do it without prefix sum we calculate total sum then while iterating
  we check whether the leftSum(which we calculate along the way) is equal to
  the rightSum which will be totalSum - leftSum - nums[i] at any point we get this
  we return that index else we return -1*/
class Solution{
public:
    int pivotIndex(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int totalSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        for(int i=0;i<nums.size();++i){
            if(leftSum == totalSum - leftSum - nums[i]){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};
