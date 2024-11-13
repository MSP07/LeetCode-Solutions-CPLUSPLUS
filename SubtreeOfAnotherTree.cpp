/*approach
  dfs
  we first start by finding same node in root as subRoot we do that by checking
  in left subtree and right subtree if the given root is not subRoot then we check
  whether both the root and subRoot are same by checking node by node using dfs*/
class Solution{
private:
    bool isIdentical(TreeNode* root,TreeNode* subTree){
        if(!root && !subTree)return true;
        if(!root || !subTree || root->val!=subTree->val)return false;
        return isIdentical(root->left,subTree->left) and isIdentical(root->right,subTree->right);
    }
public:
    bool isSubtree(TreeNode* root,TreeNode* subRoot){
        if(!root)return false;
        if(isIdentical(root,subRoot))return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};
