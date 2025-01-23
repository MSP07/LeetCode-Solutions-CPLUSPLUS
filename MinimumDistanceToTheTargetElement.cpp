/*approach
  array
  juat follow the instructions and keep track of min of abs(i-start) and finally return it*/
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                mini = min(mini,abs(i-start));
            }
        }
        return mini;
    }
};
