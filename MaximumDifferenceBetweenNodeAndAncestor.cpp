/*approach
  we iterate through the tree till end while we keep track of max and min nodes encountered so far
  then when we reach the end of the tree we simply update the ans var with whatever max value and return*/
class Solution{
private:
    int ans = 0;
    void solve(TreeNode* root,int mini,int maxi){
        if(!root){
            ans = max(ans,abs(maxi-mini));
            return;
        }
        mini = min(mini,root->val);
        maxi = max(maxi,root->val);
        solve(root->left,mini,maxi);
        solve(root->right,mini,maxi);
    }
public:
    int maxAncestorDiff(TreeNode* root){
        if(!root)return 0;
        solve(root,root->val,root->val);
        return ans;
    }
};
