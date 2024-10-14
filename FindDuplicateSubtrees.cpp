/*approach
  dfs, hashmap 
  we need to find subtrees that occur the same so first we serialize the tree by converting the whole tree to string
  we use post order traversal so we serialize left subtree , right subtree first then come to the parent node. while 
  serializing if we come across the same node and same structure again we add that to our answer and finally return 
  the answer vector*/
class Solution{
    unordered_map<string,int>subtreeCount;
    vector<TreeNode*>duplicates;
private:
    string serialize(TreeNode* root){
        if(!root)return "#";
        string left = serialize(root->left);
        string right = serialize(root->right);
        string subTree = left + "," + right + "," + to_string(root->val);
        if(subtreeCount[subTree]==1){
            duplicates.push_back(root);
        }
        subtreeCount[subTree]++;
        return subTree;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        serialize(root);
        return duplicates;
    }
};
