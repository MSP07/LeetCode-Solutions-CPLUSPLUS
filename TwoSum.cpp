class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>map1;
        for(int i=0;i<nums.size();i++){
            int tofind = target - nums[i];

            if(map1.count(tofind)){
                return {map1[tofind],i};
            }
            map1[nums[i]] = i;
        }
        return {};
    }
};
