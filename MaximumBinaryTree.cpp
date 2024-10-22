/*approach
  dfs, simulation
  we follow the given instructions and start from 0 all the way to last index
  in the given left to right range we find the highest value and point our index there
  that we take as node and recursively call for left subtree left part from that index
  and right subtree right part from that index*/
class Solution{
private:
    TreeNode* buildTree(vector<int>& nums,int left,int right){
        if(left>right)return nullptr;
        int maxInd = left;
        for(int i=left+1;i<=right;++i){
            if(nums[i]>nums[maxInd]){
                maxInd = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxInd]);
        root->left = buildTree(nums,left,maxInd-1);
        root->right = buildTree(nums,maxInd+1,right);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        return buildTree(nums,0,nums.size()-1);
    }
};
