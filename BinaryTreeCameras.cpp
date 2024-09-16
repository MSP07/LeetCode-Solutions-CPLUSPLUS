/*approach
  dfs,dp approach
  since we need to find min we need to try out all possibilites basically so that will be dp approach
  but we dont need to do try out all possible situations 
  we can take 3 states, state 0 : node has no camera and is unprotected, state 1 : node is protected
  and state 2 : node has a camera to protect
  now we recursively call the binary tree in post order (LeftRightRoot) manner and place cameras if any node is 0
  if protected or null we return 1 if it has a camera which is state 2 still it is protected so we return 1 if not 
  these two states we return unprotected or state 0 and finally return the cameras count*/
class Solution{
private:
    int dfs(TreeNode* root,int& cameras){
        if(!root)return 1;

        int left = dfs(root->left,cameras);
        int right = dfs(root->right,cameras);

        if(left==0 || right==0){
            ++cameras;
            return 2;
        }

        if(left==2 || right==2){
            return 1;
        }

        return 0;
    }
public:
    int minCameraCover(TreeNode* root){
        int cameras = 0;
        if(dfs(root,cameras)==0) ++cameras;
        return cameras;
    }
};
