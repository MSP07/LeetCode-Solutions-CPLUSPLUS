/*approach
  two pointers
  we keep two pointers one at start and other iterating
  if we come across a even numbers we swap it with the first pointer
  and increment that pointer and finally return the modified array*/
class Solution{
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        if(nums.size()==1)return nums;
        int l = 0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2==0){
                swap(nums[r],nums[l]);
                l++;
            }
        }
        return nums;
    }
};
