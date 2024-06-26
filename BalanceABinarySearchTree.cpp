/*approach
  we first find the inorder of the given tree
  then we keep two pointers one at start and another at the end 
  we start by creating new tree from the centre of the inorder array and we progrssively add
  min elements i.e. elements left to mid to the left and right to it as right part of the tree*/
class Solution{
private:
    void solve(TreeNode* root,vector<int>& inorder){
        if(!root)return;
        solve(root->left,inorder);
        inorder.push_back(root->val);
        solve(root->right,inorder);
    }
    TreeNode* ans(vector<int>& inorder,int low,int high){
        if(high<low)return nullptr;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = ans(inorder,low,mid-1);
        root->right = ans(inorder,mid+1,high);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root){
        if(!root)return root;
        vector<int>inorder;
        solve(root,inorder);
        return ans(inorder,0,inorder.size()-1);
    }
};
