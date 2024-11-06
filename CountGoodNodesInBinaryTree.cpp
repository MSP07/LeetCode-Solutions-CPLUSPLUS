/*approach
  dfs
  we keep track of highest element encountered till now by prev and by default given root is in count
  then we first calculate all the good nodes in left subtree then right subtree in either tree the 
  logiv is same we first check if curr val is greater than prev is so we incr count and update prev to that val
  else if curr val is >= prev then there a large node so we incr count but since values are same making prev = curr->val
  is waste of time so we simply incr count alone and finally return the count*/
class Solution{
    int count = 1;
private:
    void dfs(TreeNode* root,int prev){
        if(!root)return;
        if(root->val > prev){
            ++count;
            prev = root->val;
        }else if(root->val>=prev){
            ++count;
        }
        dfs(root->left,prev);
        dfs(root->right,prev);
    }
public:
    int goodNodes(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int prev = root->val;
        dfs(root->left,prev);
        dfs(root->right,prev);
        return count;
    }
};
