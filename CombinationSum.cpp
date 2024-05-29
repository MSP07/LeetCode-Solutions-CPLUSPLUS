//approach
//we keep a vector ans for the soln and ds as a data structure
//we recursively call a fn with the base case being whether the target has become 0
//in a given index we can choose to either stay and find or move to next one
//if we choose to stay when candidates[ind]<=target we push that answer into ds for future purposes and call the function again with the same index but updated target as target - candidates[ind]
//when the recursion has failed to collect the possible pairs or if there is no possible pairs in the current index the value is popped from ds
//after this we search for possible values in next index ind+1 in similar manner
//finall after iterating through the whole array we return back the answer
class Solution{
private:
    void findCombo(int ind,int target,vector<int>& candidates,vector<vector<int>>& ans,vector<int>& ds){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findCombo(ind,target-candidates[ind],candidates,ans,ds);
            ds.pop_back();
        }
        findCombo(ind+1,target,candidates,ans,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates,int target){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>>ans;
        vector<int>ds;
        findCombo(0,target,candidates,ans,ds);
        return ans;
    }
};
