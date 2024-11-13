/*approach
  dfs
  since given we need to replace the node with sum of all nodes greater than
  the given node in a "BST" this means the greatest node will not be changed
  that is the right most node will not be changed and the nodes above it will be
  changed by their sum + right most nodes sum and so on.. So this problem can be solved
  like RIGHT->ROOT->LEFT which is reverse INORDER traversal so we do that and change node->val
  for every node while keeping a global sum variable and finally return the root*/
class Solution{
    int sum = 0;
private:
    void changeBST(TreeNode* root){
        if(!root)return;
        changeBST(root->right);
        sum += root->val;
        root->val = sum;
        changeBST(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root){
        changeBST(root);
        return root;
    }
};
