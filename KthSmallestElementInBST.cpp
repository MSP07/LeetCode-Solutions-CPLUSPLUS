/*approach
  inorder traversal of BST is always sorted
  so we use that keep decr k and if we find the kth smallest before k becomes 0
  we return it else we return when k becomes 0 if k != 0 then we proceed to calculate
  right side of the tree*/
class Solution{
private:
    int find(TreeNode* root,int&k){
        if(!root)return -1;
        int left = find(root->left,k);
        if(left!=-1)return left;
        k--;
        if(k==0)return root->val;
        return find(root->right,k);
    }
public:
    int kthSmallest(TreeNode* root,int k){
        return find(root,k);
    }
};
