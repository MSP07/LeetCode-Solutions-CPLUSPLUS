/*approach
  sliding window approach
  aim is to find the length of subarray with min len such that sum >= target
  we do exactly that but brute force using two for loops and finding sum will be 
  n cube approach so we start by first adding the elements and when the element value
  exceeds target we update the len and till that sum >= target holds we update and at the same
  time shrink the window by removing previously added elements as there can be a more minimum window in the vector
  and after this we return the min len of all*/
class Solution{
public:
    int minSubarrayLen(int target,vector<int>& nums){
        int n = nums.size();
        int left = 0, len = INT_MAX, sum = 0;
        for(int right=0;right<n;++right){
            sum += nums[right];
            while(sum>=target){
                len=min(len,right-left+1);
                sum -= nums[left++];
            }
        }
        return len;
    }
};
