/*approach
  dfs
  given a node should be placed above all its lower val nodes.
  So we do that recursively, if root->val<val then we create a temp that has val in it
  and temp->left = root since root is smaller than temp and we return temp and we recursively
  call this same function for root->right also and finally return the root*/
class Solution{
public:
    TreeNode* insertIntoMaxTree(TreeNode* root,int val){
        if(!root)return new TreeNode(val);
        if(root->val<val){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        root->right = insertIntoMaxTree(root->right,val);
        return root;
    }
};
