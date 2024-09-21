/*approach
  dfs,backtracking,hashmap
  we start from root and calc sum along the way and calc no of paths to reach that currSum using hashmap
  then we increase one extra path to be reached from root to the current node we are in then recursively
  call for left and right of the node and then decrease the count in hashmap and return the no of paths finally*/
class Solution{
private:
    int find(TreeNode* root,long long currSum,int targetSum,unordered_map<long long,int>& prefixSum){
        if(!root)return 0;
        currSum += root->val;
        int numPaths = prefixSum[currSum-targetSum];
        prefixSum[currSum]++;
        numPaths += find(root->left,currSum,targetSum,prefixSum);
        numPaths += find(root->right,currSum,targetSum,prefixSum);
        prefixSum[currSum]--;
        return numPaths;
    }
public:
    int pathSum(TreeNode* root,int targetSum){
        unordered_map<long long,int>prefixSum;
        prefixSum[0] = 1;
        return find(root,0,targetSum,prefixSum);
    }
};
