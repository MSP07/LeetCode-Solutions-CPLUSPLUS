//approach
//recursively call the same function 
//when we arrive at the leaf node we just update the targetSum to the root->val
//if either of left or right comes as True then we return true else false
/*struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x), left(left), right(right) {}
};*/

class Solution{
public:
    bool hasPathSum(TreeNode* root,int targetSum){
        if(root==nullptr)return false;
        if(!root->left && !root->right)return targetSum==root->val;
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};
