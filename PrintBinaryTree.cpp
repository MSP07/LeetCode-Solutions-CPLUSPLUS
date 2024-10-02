/*approach
  dfs simulation
  we simply follow the given steps and implement them while 
  calculating height of the tree also*/
class Solution{
private:
    vector<vector<string>>res;
    int findHeight(TreeNode* root){
        if(!root)return 0;
        return 1 + max(findHeight(root->left),findHeight(root->right));
    }
    void fillMatrix(TreeNode* root,int height,int r,int c){
        if(!root)return;
        res[r][c] = to_string(root->val);
        int temp = pow(2,height-r-2);
        fillMatrix(root->left,height,r+1,c-temp);
        fillMatrix(root->right,height,r+1,c+temp);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        res.clear();
        int height = findHeight(root);
        int n = height , m = pow(2,height)-1;
        res.resize(n,vector<string>(m,""));
        fillMatrix(root,n,0,m/2);
        return res;
    }
};
