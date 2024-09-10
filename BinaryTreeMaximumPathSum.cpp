/*approach
  we calculate the highest val between left and right subtrees
  and from that i take the max one and add it to curr node and return
  this happens for every node eventually storing ans in variable declared*/
class Solution{
private:
    int pathSum(TreeNode* root,int&maxi){
        if(!root)return 0;
        int lh = max(0,pathSum(root->left,maxi));
        int rh = max(0,pathSum(root->right,maxi));
        maxi = max(maxi,lh+rh+root->val);
        return max(lh,rh) + root->val;
    }
public:
    int maxPathSum(TreeNode* root){
        int maxi = INT_MIN;
        pathSum(root,maxi);
        return maxi;
    }
};
