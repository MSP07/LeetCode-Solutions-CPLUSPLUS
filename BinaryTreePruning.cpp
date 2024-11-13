/*approach
  dfs
  aim is to prune the subtrees that have 0 in them. So we do that
  we iterate the left, right subtrees and if root node is 0 then we prune it
  we do this because if root nodes are pruned then then zero that are before them
  will become root nodes and will be pruned next*/
class Solution{
public:
    TreeNode* pruneTree(TreeNode* root){
        if(!root)return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->val==0 && !root->left && !root->right){
            return nullptr;
        }
        return root;
    }
};
