//approach
//similar to combination sum but instead we choose to go to next index as we dont want repeated elements
//if we encounter duplicate elements we just skip them
//when we come across element greater than target we just break
class Solution{
private:
    void findCombo(int index,int target,vector<vector<int>>& ans,vector<int>& ds,vector<int>& candidates){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            findCombo(i+1,target-candidates[i],ans,ds,candidates);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>>ans;
        vector<int>ds;
        findCombo(0,target,ans,ds,candidates);
        return ans;
    }
};
