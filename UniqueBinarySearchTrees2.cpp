/*approach
  recursion
  since it is given BST first we need to find all the possibilities from start to end
  and we calculate left subtree and right ones then, we iterate on left subtrees, right subtrees
  and add the diff combinations of left and right to the curr node to the ans vector and finally return the ans*/
class Solution{
private:
    vector<TreeNode*>solve(int start,int end){
        vector<TreeNode*>ans;
        if(start>end){
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=start;i<=end;++i){
            vector<TreeNode*>left = solve(start,i-1);
            vector<TreeNode*>right = solve(i+1,end);
            for(int j=0;j<left.size();++j){
                for(int k=0;k<right.size();++k){
                    TreeNode* temp = new TreeNode(i);
                    temp->left = left[j];
                    temp->right = right[k];
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*>generateBST(int n){
        return solve(1,n);
    }
};
