/*approach
  start iterating from second element and check whether the current element is less than or equal to the before element
  if the condition satisfies then their diff + 1 is added to steps as to ensure element which is lower will also be counted properly
  and we change the element also by increment so as to not cause any wrong values while checking for next element*/
class Solution{
public:
    int minToIncrementForUnique(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int steps = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                int increment = nums[i-1] - nums[i] + 1;
                steps += increment;
                nums[i] += increment;
            }
        }
        return steps;
    }
};
