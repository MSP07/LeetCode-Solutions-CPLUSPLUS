/*approach
  we use doubly linked list and a hashmap to simply perform the following
  we just update new to head->next and least used will be tail->prev and 
  we find and del,change values of keys in the hashmap*/
class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key_,int val_){
        key = key_;
        val = val_;
    }
};

class LRUCache{
private:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>m;
public:
    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void delNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key_){
        if(m.find(key_)!=m.end()){
            Node* resNode = m[key_];
            int res = resNode->val;
            m.erase(key_);
            delNode(resNode);
            addNode(resNode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            Node* existingnode = m[key_];
            m.erase(key_);
            delNode(existingnode);
        }
        if (m.size() == cap) {
            m.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }

        addNode(new Node(key_, value));
        m[key_] = head -> next;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
