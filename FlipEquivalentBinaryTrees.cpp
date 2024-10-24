/*approach
  dfs
  we check whether both the trees at any node are equal
  either without flipping or with flipping and written the
  OR of both of them*/
class Solution{
public:
    bool  flipEquiv(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2)return false;
        if(!root1 || !root2 || root1->val != root2->val)return false;
        bool withoutFlip = flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
        bool withFlip = flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
        return withoutFlip || withFlip;
    }
};
