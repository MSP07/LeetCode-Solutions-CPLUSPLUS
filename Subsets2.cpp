//approach
//we skip the duplicate elements and simply follow the method used for subsets 1
//recursively call till last element
//add all possible combos
//return
class Soltion{
private:
    void findSubs(int index,int n,vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds){
        ans.push_back(ds);
        for(int i=index;i<n;i++){
            if(i!=index && nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            findSubs(i+1,n,nums,ans,ds);
            ds.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>&nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>>ans;
        vector<int>ds;
        findSubs(0,nums.size(),nums,ans,ds);
        return ans;
    }
};
