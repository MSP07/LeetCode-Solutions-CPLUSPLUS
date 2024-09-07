/*approach
  recursive approach
  we traverse and try to find head before finding head if the tree runs out then it is a false
  else if the head runs out then we have iterated the linked list so it is true. first we start by searching head
  in either left or right part of subtree then if we found one we try and find the remaining part of linked list
  either it is in left subTree from the next node or right subTree from the next node if in either left or right part
  we find the linked list we return true*/
class Solution{
private:
    bool dfs(ListNode* head,TreeNode* root){
        if(!head)return true;
        if(!root)return false;
        if(head->val != root->val)return false;
        return dfs(head->next,root->left) || dfs(head->next,root->right);
    }
    bool subPath(ListNode* head,TreeNode* root){
        if(!root)return false;
        return dfs(head,root) || subPath(head,root->left) || subPath(head,root->right);
    }
public:
    bool isSubPath(ListNode* head,TreeNode* root){
        return subPath(head,root);
    }
};
