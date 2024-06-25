/*approach
  we make use of the fact that given tree is bst so greater elements will be in the right
  we iterate entirely through right side of the tree and keep summing up the values of the nodes
  then we replace the node val with ans and iteratively call the left side of the tree(other side)
  then finally we return the root of the tree we changed*/
class Solution{
private:
    void convertRaReNana(int&ans,TreeNode* root){
        if(!root)return;
        convertRaReNana(ans,root->right);
        ans += root->val;
        root->val = ans;
        convertRaReNana(ans,root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root){
        int ans = 0;
        convertRaReNana(ans,root);
        return root;
    }
};
