class Solution{
private:
    TreeNode* getMin(TreeNode* root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root,int key){
        if(!root)return nullptr;
        if(key<root->val){
            root->left = deleteNode(root->left,key);
        }else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }else{
            if(!root->left&&!root->right){
                delete root;
                return nullptr;
            }else if(!root->left){
                TreeNode* TempRight = root->right;
                delete root;
                return TempRight;
            }else if(!root->right){
                TreeNode* TempLeft = root->left;
                delete root;
                return TempLeft;
            }else{
                TreeNode* successor = getMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right,successor->val);
            }
        }
        return root;
    }
};
