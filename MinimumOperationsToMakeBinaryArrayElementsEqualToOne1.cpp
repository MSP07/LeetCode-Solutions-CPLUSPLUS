/*approach
  sliding window
  if nums[i]==0 then we have a element or order of elements to flip
  if we go out of index we return -1 i+1 >= n or i+2 >= n return -1
  else we change the elements nums[i+1] = 1 - nums[i+1] and nums[i+2] = 1 - nums[i+2]
  this way we flip the elements 1 ot 0 and 0 to 1 and so if there are 0's again we need to flip
  them so we count that in ans and again change the consec 2 elements we do this till we reach the end*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(),ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans++;
                if(i+1>=n || i+2>=n)return -1;
                nums[i+1] = 1 - nums[i+1];
                nums[i+2] = 1 - nums[i+2];
            }
        }
        return ans;
    }
};
