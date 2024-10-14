/*approach
  bfs, simulation
  we iterate through the levels of tree and when we reach the required depth we add new nodes to next
  of it for every node in the level and the next of the new nodes will be the existing left subtree and 
  right subtree of that node. If not we simply push them into queue and keep on iterating while increasing 
  the level count and if we reach the required level we perform the above operation and break the loop and 
  return the root*/
class Solution{
public:
    TreeNode* addOneRow(TreeNode* root,int val,int depth){
        if(depth==1){
            TreeNode* curr = new TreeNode(val);
            curr->left = root;
            return curr;
        }
        queue<TreeNode*>q;
        q.push(root);
        int currDepth = 1;
        while(!q.empty()){
            int size = q.size();
            if(currDepth == depth-1){
                for(int i=0;i<size;++i){
                    TreeNode* curr = q.front();
                    q.pop();
                    TreeNode* tempLeft = curr->left;
                    TreeNode* tempRight = curr->right;
                    curr->left = new TreeNode(val);
                    curr->left->left = tempLeft;
                    curr->right = new TreeNode(val);
                    curr->right->right = tempRight;
                }
                break;
            }
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return root;
    }
};
