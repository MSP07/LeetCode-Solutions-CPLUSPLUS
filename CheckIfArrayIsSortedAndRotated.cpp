/*approach
  array
  if the array is sorted and rotated there must be exactly
  only one point where nums[i] < nums[i-1] since it is sorted'
  and rotated so we check for the extreme elements first as there is a chance
  the array is sorted and rotated at last index and we check from first index all
  the to last if(nums[i]<nums[i-1]) if so we incr cnt and we simulataneously check  
  whether cnt > 1, if so we return false there itself else finally after the loop we return true*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        if(nums[0]<nums[nums.size()-1])cnt++;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                cnt++;
                if(cnt>1)return false;
            }
        }
        return true;
    }
};
