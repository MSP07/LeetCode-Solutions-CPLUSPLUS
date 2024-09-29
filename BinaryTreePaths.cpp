/*approach
  dfs
  we iterate till the leaf node and convert the nodes val to string 
  finally when we come to leaf node we add the leaf node to the string 
  and add it to the vector*/
class Solution{
private:
    void dfs(TreeNode* root,vector<string>& paths,string res){
        if(!root)return;
        if(!root->left && !root->right){
            paths.push_back(res+to_string(root->val));
            return;
        }
        res += to_string(root->val) + "->";
        dfs(root->left,paths,res);
        dfs(root->right,paths,res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root){
        vector<string>paths;
        dfs(root,paths,"");
        return paths;
    }
};
