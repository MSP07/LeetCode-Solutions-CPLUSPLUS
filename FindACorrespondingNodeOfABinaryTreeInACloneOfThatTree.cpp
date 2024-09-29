/*approach
  bfs/dfs approach
  we simply find the node that equals target->val on cloned treeNode and return that
  else we return nullptr*/
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(cloned->val==target->val)return cloned;
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val==target->val)return curr;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return nullptr;
    }
};
