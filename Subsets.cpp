//approach
//we should iterate throughout the array till the end in every case, so that will be our base case. when index==n we return
//if not we push the array elements and recursively call the function for next index in the next step. This gives us whole array [1 element, 2 element, ... , nth element]
//so in the next step we pop the last element and again call the same function with index+1 in the next step
//this recursion function makes sure to cover all the subsets
class Solution{
private:
    void findAns(int index,int n,vector<int>& ds,vector<vector<int>>& ans,vector<int>& nums){
        if(index==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        findAns(index+1,n,ds,ans,nums);
        ds.pop_back();
        findAns(index+1,n,ds,ans,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        findAns(0,n,ds,ans,nums);
        return ans;
    }
};
