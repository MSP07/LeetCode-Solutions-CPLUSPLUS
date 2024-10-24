/*approach
  bfs approach
  we do level order traversal then connect
  all the next nodes in the same level
  and finally return root*/
class Solution{
public:
    Node* connect(Node* root){
        if(!root)return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                Node* curr = q.front();
                q.pop();
                if(i<size-1){
                    curr->next = q.front();
                }
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
        }
        return root;
    }
};
