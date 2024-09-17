/*approach
  dp,postorder approach
  we try out all the dubtrees of the root in postorder(LeftRightRoot) manner so as to cover all possibilites
  we check for the sum of left and right subtrees add them and we return whether subtree can be formed if it can be
  we also update maxSum accordingly our recursive base case will be to return true as we have reached the end with extreme
  high and low values and with 0 as sum of node like this we can update and return the maxSum*/
class Solution{
    int maxSum = 0;
private:
    Subtree helper(TreeNode* root){
        if(!root)return {true,INT_MIN,INT_MAX,0};

        Subtree left = helper(root->left);
        Subtree right = helper(root->right);

        if(left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal){
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum,currSum);
            return {true,min(left.minVal,root->val),max(right.maxVal,root->val),currSum};
        }
        return {false,0,0,0};
    }
public:
    int maxSumBST(TreeNode* root){
        helper(root);
        return maxSum;
    }
};
