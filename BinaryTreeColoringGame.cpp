/*approach
  dfs approach
  after the first player chooses we can either choose the left subtree or right aubtree after that node
  or the remaining part of the tree and if any one of these can give us more nodes than half of the while nodes
  we can successfully make the player 2 win the game else not*/
class Solution{
private:
    int countNodes(TreeNode* root){
        if(!root)return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    void findNode(TreeNode*& xPointer,TreeNode* root,int x){
        if(!root)return;
        if(root->val==x){
            xPointer = root;
            return;
        }
        findNode(xPointer,root->left,x);
        findNode(xPointer,root->right,x);
    }
public:
    bool btreeGameWinningMove(TreeNode* root,int x,int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        TreeNode* xPointer = root;
        findNode(xPointer,root,x);

        int leftSubTreeNodes = countNodes(xPointer->left);
        int rightSubTreeNodes = countNodes(xPointer->right);

        int remaining = n - (leftSubTreeNodes + rightSubTreeNodes + 1);
        int target = n/2;
        if(target<leftSubTreeNodes || target < rightSubTreeNodes || target < remaining){
            return true;
        }
        return false;
    }
};
