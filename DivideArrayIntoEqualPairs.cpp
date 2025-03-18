/*approach
  sorting,hashmap
  if to solve in 0(1) space complexity we can first
  sort the given array and then check if adj elements are same for every pair
  if not for any instance return false else finally return true*/
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i+=2){
            if(nums[i]!=nums[i+1])return false;
        }
        return true;
    }
};
