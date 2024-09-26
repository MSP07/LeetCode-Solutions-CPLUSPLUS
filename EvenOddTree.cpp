/*approach
  bfs
  we iterate through trees by level using bfs/queue approach for each level
  accordingly with whether odd or even we check for the conditions and at any level
  the conditions dont match we return false else we increase the level and iterate the whole tree
  and finally if no negations are found of the given condition we can return true*/
class Solution{
public:
    bool isEvenOddTree(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        queue<TreeNode*>q;
        int level = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int prev = (level%2==0) ? INT_MIN : INT_MAX;
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front();
                q.pop();
                if(level%2){
                    if(curr->val%2 || curr->val >= prev)return false;
                }else{
                    if(curr->val%2==0 || curr->val <= prev)return false;
                }
                prev = curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ++level;
        }
        return true;
    }
};
