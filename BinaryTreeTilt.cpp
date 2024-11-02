/*approach
  dfs
  start from root node and calulate sum of leftTree and rightTree recursively
  totalTilt will be the abs(leftTree - rightTree) for every node and finally return that totalTilt*/
class Solution{
  int totalTilt = 0;
private:
    int dfs(TreeNode* root){
        if(!root)return 0;
        int leftTree = dfs(root->left);
        int rightTree = dfs(root->right);
        totalTilt += abs(leftTree - rightTree);
        return root->val + leftTree + rightTree;
    }
public:
    int findTilt(TreeNode* root){
        dfs(root);
        return totalTilt;
    }
};
