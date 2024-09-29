/*approach
  dfs approach
  since our goal is find the min path we return a huge val if we dont find one
  else if we do reach the leaf node we return 1 indicating there is one path
  and we recursively call left and right paths + 1 as answer*/
class Solution{
private:
    int dfs(TreeNode* root){
        if(!root)return INT_MAX;
        if(!root->left && !root->right)return 1;
        return 1 + min(dfs(root->left),dfs(root->right));
    }
public:
    int minDepth(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(!root)return 0;
        return dfs(root);
    }
};
