/*approach
  dfs,hashmap
  first we calculate all the possible subtree sum and keep a track of times they occur
  then we find the sum that has occured the most and then we push that into our answer
  and we simply return it*/
class Solution{
    unordered_map<int,int>freqSum;
private:
    int findSum(TreeNode* root){
        if(!root)return 0;
        int sum = root->val + findSum(root->left) + findSum(root->right);
        freqSum[sum]++;
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root){
        findSum(root);
        int maxi = INT_MIN;
        for(auto it:freqSum){
            maxi = max(maxi,it.second);
        }
        vector<int>ans;
        for(auto it:freqSum){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
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
