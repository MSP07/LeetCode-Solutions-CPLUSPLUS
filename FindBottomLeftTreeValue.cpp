/*approach
  bfs approach
  we start by initialising our result to root->val
  push the root into queue and for the no of nodes in each level we iterate the level and 
  we update our result to the first node value in each level as that will be the leftmost value
  and finally return the result*/
class Solution{
public:
    int findBottomValue(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        int res = root->val;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;++i){
                auto curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(i == 0) res = curr->val;
            }
        }
        return res;
    }
};
