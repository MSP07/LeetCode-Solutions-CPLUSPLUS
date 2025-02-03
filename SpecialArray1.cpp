/*approach
  array, simulation
  if two continuous elements in the array have same parity we return false
  else finally we return true*/
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int i=0;
        while(i<nums.size()-1){
            int j = i+1;
            if(nums[i]%2 == nums[j]%2)return false;
            i++;
        }
        return true;
    }
};
