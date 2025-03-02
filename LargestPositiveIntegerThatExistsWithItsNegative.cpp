/*approach
  hashmap, sorting
  we use set to take all the elements then we sort the array
  traverse from last since larger elements in the back and check
  for its negative in that set if there is negative element of that num
  then we return that num else finally we return -1*/
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j = nums.size()-1;
        unordered_set<int>hashi(nums.begin(),nums.end());
        while(j>=0){
            if(hashi.count(-nums[j]))return nums[j];
            j--;
        }
        return -1;
    }
};
