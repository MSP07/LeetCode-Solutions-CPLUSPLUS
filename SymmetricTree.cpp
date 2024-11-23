/*approach
  dfs
  we follow simple recursion starting from root->left and root->right
  if both nodes are equal and their {left->left,right->right} and {left->right,right->left}
  are same we return true else in any node if both nodes are not equal or we have
  only one node and not the other we return false*/
class Solution{
private:
    bool SymmetricCheck(TreeNode* left,TreeNode* right){
        if(!left && !right)return true;
        if(!left || !right)return false;
        return left->val == right->val && SymmetricCheck(left->left,right->right) && SymmetricCheck(left->right,right->left);
    }
public:
    bool isSymmetric(TreeNode* root){
        if(!root->left && !root->right)return true;
        return SymmetricCheck(root->left,root->right);
    }
};
