class Solution{
public:
    int maxProduct(vector<int>& nums){
        if(nums.size()==0)return 0;
        int maxSoFar = nums[0], minSoFar = nums[0], ans = maxSoFar;
        for(int i=1;i<nums.size();i++){
            int tempMaxSoFar = max(nums[i],max(nums[i]*maxSoFar,nums[i]*minSoFar));
            minSoFar = min(nums[i],min(nums[i]*maxSoFar,nums[i]*minSoFar));
            maxSoFar = tempMaxSoFar;
            ans = max(ans,maxSoFar);
        }
        return ans;
    }
};
