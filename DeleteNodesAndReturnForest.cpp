/*approach
  we iterate from root if we find a node in to_delete then if there are 
  children for it we store it and delete the node and return nullptr else
  we return the node itself. by this way we push every node into the ans*/
class Solution{
private:
    TreeNode* delNodes(TreeNode* root,unordered_set<int>& lookup,vector<TreeNode*>& forest){
        if(!root)return nullptr;
        root->left = delNodes(root->left,lookup,forest);
        root->right = delNodes(root->right,lookup,forest);
        if(lookup.find(root->val)!=lookup.end()){
            if(root->left)forest.push_back(root->left);
            if(root->right)forest.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<int>lookup(to_delete.begin(),to_delete.end());
        vector<TreeNode*>forest;
        if(delNodes(root,lookup,forest)){
            forest.push_back(root);
        }
        return forest;
    }
};
