/*approach
  array
  iterate till i+2 < nums.size() and check if
  nums[i] + nums[i+2] is half of nums[i+1] if so we found a subarray
  we incr the count and finally return that count*/
class Solution {
public:
    int countSubarrays(vector<int>& nums, int count = 0) {
        for (int i = 0 ;i + 2 < nums.size(); i++)
            if (2 * (nums[i] + nums[i + 2]) == nums[i + 1]) 
                count++;
        return count;
    }
};
