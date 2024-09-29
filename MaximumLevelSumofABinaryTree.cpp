/*approach
  bfs approach
  we iterate through each level calculate the sum
  and keep track of maxSum in each level calculated and
  its corresponding level and finally return the level*/
class Solution{
public:
    int maxLevelSum(TreeNode* root){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        queue<TreeNode*>q;
        q.push(root);
        int level = 1,maxSum = INT_MIN,maxLevel = 1;
        while(!q.empty()){
            int size = q.size();
            int lvlSum = 0;
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front();
                q.pop();
                lvlSum += curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            if(lvlSum > maxSum){
                maxSum = lvlSum;
                maxLevel = level;
            }
            level++;
        }
        return maxLevel;
    }
};
