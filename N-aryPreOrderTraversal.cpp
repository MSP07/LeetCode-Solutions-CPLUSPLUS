/*approach
  dfs
  preorder = ROOT LEFT RIGHT
  so first push the root and call recursively for left and right
  since this is N-ary we call for the whole child in children*/
class Solution{
private:
    void solve(Node* root,vector<int>& ans){
        if(!root)return;
        ans.push_back(root->val);
        for(auto child:root->children){
            solve(child,ans);
        }
    }
public:
    vector<int>preOrder(Node* root){
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};
