/*approach
  from the current node whatever the val the lies in next nodes will have node val*10+root->val
  meaning prev num*10 + current node val will be the number that we are looking for we simply calculate this
  till end of tree using dfs for left side and right side when we reach the leaf node we add the values calculated
  to ans and return it*/
class Solution {
private:
    void find(TreeNode* root,int num,int&ans){
        num = num*10 + root->val;
        if(!root->left && !root->right){
            ans += num;
            return;
        }
        if(root->left) find(root->left,num,ans);
        if(root->right) find(root->right,num,ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        find(root,0,ans);
        return ans;
    }
};
