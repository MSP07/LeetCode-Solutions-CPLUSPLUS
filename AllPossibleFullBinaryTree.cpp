/*approach
  dp-memoize approach
  if the n is even we cant form a tree because 1 node is always root and the remaining is even as 0 or 2 nodes
  so 1 + even is always odd. we divide that into diff combos for left and right trees and we recursively call the 
  fn to create new nodes of 0 and return it. And we add them to our answer too. Since this might take a very high
  time complexity we use memoization to encounter overlapping subproblems and finally return the answer vector we
  have stored the treenodes on*/
class Solution{
private:
    vector<TreeNode*>generateBST(int n,unordered_map<int,vector<TreeNode*>>& memo){
        if(memo.find(n)!=memo.end())return memo[n];
        if(n%2==0)return {};
        if(n==1)return {new TreeNode(0)};
        vector<TreeNode*>result;
        for(int leftTree=1;leftTree<n;leftTree+=2){
            int rightTree = n - 1 - leftTree;
            for(TreeNode* left:generateBST(leftTree,memo)){
                for(TreeNode* right:generateBST(rightTree,memo)){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return memo[n] = result;
    }
public:
    vector<TreeNode*>allPossibleBST(int n){
        unordered_map<int,vector<TreeNode*>>memo;
        return generateBST(n,memo);
    }
};
