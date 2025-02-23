/*approach
  binary tree, recursion
  given two preorder and postorder arrays 
  the root node will be same so we start with two pointers i and j
  we first take the preorder[i] and increase i and check whether the new root(root = preorder[i])
  is same as postorder if not we recursively take the preorder[i] as root->left and again check the same
  this time for root->eight and finally increase j pointer and return root*/
class Solution{
private:
    TreeNode* construct(int i,int j,vector<int>& preorder,vector<int>& postorder){
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        if(root->val!=postorder[j]){
            root->left = construct(i,j,preorder,postorder);
        }
        if(root->val!=postorder[j]){
            root->right = construct(i,j,preorder,postorder);
        }
        j++;
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,vector<int>& postorder){
        int i = 0, j = 0;
        return construct(i,j,preorder,postorder);
    }
};
