/*approach
  dfs approach
  we start by including curr node as string to our ans string then we give priority to the left subtree
  if there is left subtree or right we choose left as default as per condition then after that since there
  is a chance that there is a right subtree and that must be included we check for it after checking for left
  subtree and add the right subtree also*/
class Solution{
private:
    void fill(TreeNode* root,string& ans){
        if(!root)return;
        ans += to_string(root->val);
        if(root->left || root->right){
            ans += "(";
            fill(root->left,ans);
            ans += ")";
        }
        if(root->right){
            ans += "(";
            fill(root->right,ans);
            ans += ")";
        }
    }
public:
    string tree2str(TreeNode* root){
        string ans = "";
        fill(root,ans);
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
