/*approach
  hashmap
  we iterate the bst inorder way and take count of vals that occur 
  we keep track of maximum occuring value also and then we iterate the
  hashmap again and append the values to ans and return*/
class Solution{
    unordered_map<int,int>freqMap;
    int maxOccur = 0;
private:
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        freqMap[root->val]++;
        maxOccur=max(maxOccur,freqMap[root->val]);
        inorder(root->right);
    }
public:
    vector<int> findMode(TreeNode* root){
        vector<int>ans;
        inorder(root);
        for(auto& [val,freq] : freqMap){
            if(freq==maxOccur){
                ans.push_back(val);
            }
        }
        return ans;
    }
};
