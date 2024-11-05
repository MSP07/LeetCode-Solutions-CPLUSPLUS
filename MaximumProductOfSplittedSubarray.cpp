/*approach
  dfs
  aim is to calculate max prod of two subtrees from org tree
  so first we can calculate total tree's sum and then for each node we calculate a subtree sum for its left and right subtree
  then the other sum will be totalSum - subTreeSum and we take product of them and keep track of the max one and return it finally*/
class Solution{
    const int MOD = 1e9+7;
    long long totalSum = 0;
    long long prod = 0;
private:
    long long findSum(TreeNode* root){
        if(!root)return 0;
        return root->val + findSum(root->left) + findSum(root->right);
    }
    long long findProd(TreeNode* root){
        if(!root)return 0;
        long long subTreeSum = root->val + findProd(root->left) + findProd(root->right);
        prod = max(prod,subTreeSum*(totalSum-subTreeSum));
        return subTreeSum;
    }
public:
    int maxProd(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        totalSum = findSum(root);
        findProd(root);
        return prod % MOD;
    }
};
