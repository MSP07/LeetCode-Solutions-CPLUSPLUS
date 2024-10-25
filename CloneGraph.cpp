/*approach
  hashmap
  we use hashmap to keep track of nodes and
  clone that nodes to newly creating ones*/
class Solution {
    unordered_map<Node*,Node*>clone;
public:
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        if(clone.find(node)!=clone.end()){
            return clone[node];
        }
        Node* curr = new Node(node->val);
        clone[node] = curr;
        for(Node* neighbor : node->neighbors){
            curr->neighbors.push_back(cloneGraph(neighbor));
        }
        return curr;
    }
};
