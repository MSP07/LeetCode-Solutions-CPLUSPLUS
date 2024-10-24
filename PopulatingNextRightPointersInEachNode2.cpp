/*approach
  bfs
  same logic as the first version of this same problem*/
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
