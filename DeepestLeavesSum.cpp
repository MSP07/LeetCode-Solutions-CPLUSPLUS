/*approach
  bfs approach
  we traverse level order and we keep count of how many nodes are leaf in that level
  if the level's size is equal to the count then that will be the last level so we return the
  sum of the nodes in that level which we will store in a ds for every level*/
class Solution{
public:
    int deepestLeavesSum(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>ds;
            int cnt = 0;
            int size = q.size();
            for(int i=0;i<size;++i){
                auto node = q.front();
                q.pop();
                ds.push_back(node->val);
                if(!node->left && !node->right){
                    cnt++;
                }

                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(cnt == size){
                return accumulate(ds.begin(),ds.end(),0);
            }
        }
        return -1;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
