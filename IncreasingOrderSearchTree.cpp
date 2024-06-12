/*approach
  dfs approach
  find inorder and create new tree while pushing elements in order of the inorder traversal*/
class Solution{
private:
    void findIn(TreeNode* root,vector<int>& inorder){
        if(!root)return;
        findIn(root->left,inorder);
        inorder.push_back(root->val);
        findIn(root->right,inorder);
    }
public:
    TreeNode* increasingBST(TreeNode* root){
        vector<int>inorder;
        findIn(root,inorder);
        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;
        for(int val:inorder){
            curr->right = new TreeNode(val);
            curr = curr->right;
        }
        return dummy->right;
    }
};
