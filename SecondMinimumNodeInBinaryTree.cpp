/*approach
  dfs approach
  by the given properties the root node will be min node
  so if we find a node greater than this node and less than secondMin which we can assume to be LONG_MAX
  we update that to secondMin and return it finally if val is changed else we return -1*/
class Solution{
private:
    void dfs(TreeNode* root,int& curr,long& prev){
        if(!root)return;
        if(root->val > curr && root->val < prev){
            prev = root->val;
        }
        dfs(root->left,curr,prev);
        dfs(root->right,curr,prev);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int curr = root->val;
        long prev = LONG_MAX;
        dfs(root,curr,prev);
        return (prev==LONG_MAX) ? -1 : prev;
    }
};
