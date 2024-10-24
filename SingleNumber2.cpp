/*approach
  sorting
  we sort and iterate over 3 indices if duplicate any element is found such that
  that dosen't have 3 duplicates we return that num else we return the last element
  bit manipulation
  ones,twos are calculated from the nums and their XOR is the answer*/
class Solution{
public:
    int singleNumber(vector<int>& nums){
        //sorting
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i+=3){
            if(nums[i]!=nums[i+1])return nums[i];
        }
        return nums.back();
        //bit manipulation
        int ones = 0, twos = 0;
        for(int num:nums){
            ones = (ones^num) & ~twos;
            twos = (twos^num) & ~ones;
        }
        return ones;
    }
};
