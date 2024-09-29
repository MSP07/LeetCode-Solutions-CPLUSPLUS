/*approach
  bfs traversal
  we use bfs to make level order traversal
  and keep track of level and return the level finally*/
class Solution{
public:
    int maxDepth(Node* root) {
        if(!root)return 0;
        int level = 0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                Node* curr = q.front();
                q.pop();
                for(Node* child:curr->children){
                    q.push(child);
                }
            }
            ++level;
        }
        return level;
    }
};
