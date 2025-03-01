/*approach
  two pointers, simulation
  we first change the given array as per rules and then we take one pointer at
  start and swap the non zero element with that pointer element and increase the pointer
  and finally return the modified array saving space*/
class Solution{
public: 
    vector<int> applyOperations(vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int l = 0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]!=0){
                swap(nums[r],nums[l]);
                l++;
            }
        }
        return nums;
    }
};
