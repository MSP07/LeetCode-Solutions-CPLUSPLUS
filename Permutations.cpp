/*approach
  backtracking
  we rearrange the elements in nums and add them to our ans
  we do this by using backtracking. For given ind we re-arrange
  elements by swapping elements at the ind and at i for i iterations
  and then finally return the ans vector*/
class Solution{
private:
    void fill(int ind,vector<int>& nums,vector<vector<int>>& ans){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            fill(ind+1,nums,ans);
            swap(nums[ind],nums[i]);
        }
    }
public:
    vector<vector<int>> permutate(vector<int>& nums){
        vector<vector<int>>ans;
        fill(0,nums,ans);
        return ans;
    }
};
