/*approach
  iterate through the first tree push its elements
  then iterate through second tree and push its elements
  then sort the vector and return*/
class Solution{
public:
    void find1(TreeNode* root1,vector<int>& tree){
        if(!root1)return;
        tree.push_back(root1->val);
        if(root1->left)find1(root1->left,tree);
        if(root1->right)find1(root1->right,tree);
    }
    void find2(TreeNode* root2,vector<int>& tree){
        if(!root2)return;
        tree.push_back(root2->val);
        if(root2->left)find2(root2->right,tree);
        if(root2->right)find2(root2->right,tree);
    }
public:
    vector<int> getAllElements(TreeNode* root1,TreeNode* root2){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>tree;
        find1(root1,tree);
        find2(root2,tree);
        sort(tree.begin(),tree.end());
        return tree;
    }
};
