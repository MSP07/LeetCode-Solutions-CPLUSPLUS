/*approach
  bfs approach
  we initially check whether is there a root or not if not we return empty array
  we then traverse through each level of tree using queue and bfs and calculate max element
  and then finally push the maximum element to the answer and return the ans array*/
class Solution{
public:
    vector<int> largestValues(TreeNode* root){
        vector<int>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int lvlSize = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<lvlSize;++i){
                auto curr = q.front();
                q.pop();
                maxi = max(maxi,curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
