/*approach
  bfs,hashmap approach
  we keep track of levels and use a temp hashmap to store
  the odd level nodes and after that level we reverse that in 
  the same tree and move on to next lvl increasing the lvl variable
  and at the same time clearing the temp hashmap and after the full
  process we return the root of the tree*/
class Solution{
public:
    TreeNode* reverseOddLevels(TreeNode* root){
        vector<TreeNode*>nodes;
        queue<TreeNode*>q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(lvl%2)nodes.push_back(curr);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            if(lvl%2){
                for(int i=0;i<nodes.size()/2;i++){
                    swap(nodes[i]->val,nodes[nodes.size()-i-1]->val);
                }
            }
            nodes.clear();
            lvl++;
        }
        return root;
    }
};
