/*approach
  backtrcking
  we start by adding root to a ds
  then we keep on iterating throughout left and right subtrees subtracting root values
  when we reach leaf nodes we check whether we have completed the targetSum if yes we add ds
  to ans else we try out left and right trees by subtracting current nodes values from targetSum
  to try diff paths we pop the values from back in ds*/
class Solution{
private:
    void findPaths(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int>& ds){
        if(!root)return;
        ds.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum){
            ans.push_back(ds);
        }else{
            findPaths(root->left,targetSum-root->val,ans,ds);
            findPaths(root->right,targetSum-root->val,ans,ds);
        }
        ds.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root,int targetSum){
        vector<vector<int>>ans;
        vector<int>ds;
        findPaths(root,targetSum,ans,ds);
        return ans;
    }
};
