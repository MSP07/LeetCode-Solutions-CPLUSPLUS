/*approach
  two pointers
  we check for every pair of indices in nums and return the ones
  that satisfies the given conditions*/
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                if(abs(i-j)>=indexDifference && abs(nums[i]-nums[j])>=valueDifference){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};
