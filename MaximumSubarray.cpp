//approach
//we keep two var sum and max till an element and intialise both to the first element
//we then iterate from 2nd element till lase updating sum to the max btn the current element and sum of previous element with curr element(since there are negative number possible)
//then we update our max var with max of that var or the updated sum var
//finally we return the max var
class Solution{
public:
    int maxSubarray(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int sum = nums[0];
        int maxi = nums[0];
        for(int i=1;i<nums.size();i++){
            sum = max(nums[i],sum+nums[i]);
            maxi = max(sum,maxi);
        }
        return maxi;
    }
};
