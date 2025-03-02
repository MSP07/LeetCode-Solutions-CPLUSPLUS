/*approach
  hashmap
  to solve this efficiently we use hashmap and we iterate in nums
  for each num if there is num+diff and num+2*diff then there is a triplet 
  so we increase the count and finally return it*/
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0;
        unordered_set<int>hashi(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(hashi.count(nums[i]+diff) && hashi.count(nums[i]+2*diff)){
                cnt++;
            }
        }
        return cnt;
    }
};
