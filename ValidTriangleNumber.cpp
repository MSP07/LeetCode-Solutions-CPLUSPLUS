/*approach
  greedy approach
  we sort the nums in non-decreasing order for convinence
  if a+b>c and a<=b<=c
  then the sides are valid. So we iterate from last to
  1st index element and check for the above condition if the 
  condition is satisfied then the entire range of nums satisfies it as 
  the nums is sorted in non-decreasing manner and we decrease the right window
  else we increase the left window and we return the count after iteration*/
class Solution{
public:
    int triangleNumber(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i=n-1;i>=2;--i){
            int left = 0, right = i-1;
            while(left<right){
                if(nums[left]+nums[right]>nums[i]){
                    cnt += right - left;
                    right--;
                }else{
                    left++;
                }
            }
        }
        return cnt;
    }
};
