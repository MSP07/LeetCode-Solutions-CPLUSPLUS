/*approach
  we use dfs approach to reach till leaf while still maintaining distance
  we keep leftdist and rightdist and if l + r <= distnace we increase our
  final result and we keep track of distances from current node too as if
  l+1 < distance and r + 1 < distance they are valid and can be included*/
class Solution{
private:
    vector<int> dfs(TreeNode* root,int&distance,int&result){
        if(!root)return {};
        if(!root->left && !root->right)return {1};
        vector<int> leftDist = dfs(root->left,distance,result);
        vector<int> rightDist = dfs(root->right,distance,result);
        for(int l:leftDist){
            for(int r:rightDist){
                if(l+r<=distance)++result;
            }
        }
        vector<int> currentDist;
        for(int l:leftDist){
            if(l+1<distance){
                currentDist.push_back(l+1);
            }
        }
        for(int r:rightDist){
            if(r+1<distance){
                currentDist.push_back(r+1);
            }
        }
        return currentDist;
    }
public:
    int countPairs(TreeNode* root,int distance){
        int result = 0;
        dfs(root,distance,result);
        return result;
    }
};
