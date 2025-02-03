/*approach
  backtracking, hashmap
  the idea is to backtrack swap elements and add them recursively
  in the ans while checking whether the element at that particular index
  has already swapped, if so we continue else we add that element to hashmap
  and finally return the ans vector/list*/
class Solution {
private:
    void fill(int ind,vector<vector<int>>& ans,vector<int>& nums){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>seen;
        for(int i=ind;i<nums.size();i++){
            if(seen.count(nums[i]))continue;
            seen.insert(nums[i]);
            swap(nums[i],nums[ind]);
            fill(ind+1,ans,nums);
            swap(nums[i],nums[ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        fill(0,ans,nums);
        return ans;
    }
};
