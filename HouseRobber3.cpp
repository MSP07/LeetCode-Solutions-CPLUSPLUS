/*approach
  we iteratively collect values of leftsubtree and rightsubtree
  then we either choose the root node or not. if we include then
  we add the root node val to next next node of left and right subtree
  else if we do not take the root node we simply choose the max of 2 of
  leftsubtree and 2 of rightsubtree and return them. then we return the max
  value of them both*/
class Solution{
private:
    vector<int> heist(TreeNode* root){
        if(!root)return {0,0};
        vector<int> leftSubTree = heist(root->left);
        vector<int> rightSubTree = heist(root->right);
        int include = root->val + leftSubTree[1] + rightSubTree[1];
        int exclude = max(leftSubTree[0],leftSubTree[1]) + max(rightSubTree[0],rightSubTree[1]);
        return {include,exclude};
    }
public:
    int rob(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>result = heist(root);
        return max(result[0],result[1]);
    }
};
