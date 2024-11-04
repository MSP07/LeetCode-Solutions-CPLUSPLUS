/*approach
  dfs, postorder
  since we need to get the coins val in every node we first need to explore
  all nodes so we use postOrder traversal then we calculate node-1 to identify
  whether to add coins or subtract from the curr node and to calculate moves
  we take help of leftExcess and rightExcess calculation and calculate moves and return it*/
class Solution{
    int moves = 0;
private:
    int postOrder(TreeNode* root){
        if(!root)return 0;
        int leftExcess = postOrder(root->left);
        int rightExcess = postOrder(root->right);
        moves += abs(leftExcess) + abs(rightExcess);
        return root->val + leftExcess + rightExcess - 1;
    }
public:
    int distributecoins(TreeNode* root){
        postOrder(root);
        return moves;
    }
};
