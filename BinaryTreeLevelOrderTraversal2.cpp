/*approach
  bfs
  we simply iterate through the level and add elements like level order traversal
  finally reverse that and return the answer*/
class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>ds;
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front();
                q.pop();
                ds.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(ds);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
