/*approach
  sorting,hashmap
  we sort the array and find the smaller numbers than the current number
  we use hashmap to store the indices with the numbers and then we 
  tahe the count from the hashmap store it in array and return it*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        unordered_map<int, int> rank;
        for(int i = 0;i<sorted_nums.size();i++){
            if(rank.find(sorted_nums[i]) == rank.end()){
                rank[sorted_nums[i]] = i;
            }
        }
        vector<int> result;
        for(int num : nums){
            result.push_back(rank[num]);
        }
        return result;
    }
};
