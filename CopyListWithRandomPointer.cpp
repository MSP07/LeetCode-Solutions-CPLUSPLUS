/*approach
  brute force we first create the given nodes without random pointer while using hashmap
  to store the nodes locations and then in the second iteration we use the hashmap to create
  random pointers for the created nodes too
  in optimal approach
  we omit hashmap with the logic that if there happens to be a random pointer then it will satisfy
  the condition curr->next->random = curr->random->next and we move curr to curr->next->next*/
class Solution{
public:
    //brute force approach
    Node* copyRandomList(Node* head){
        Node* dummy = new Node(0);
        Node* ans = dummy, *temp = head;
        map<Node*,Node*>m;
        while(temp){
            ans->next = new Node(temp->val);
            m[temp] = ans->next;
            ans = ans->next;
            temp = temp->next;
        }
        temp = head;
        ans = dummy->next;
        while(temp){
            ans->random = m[temp->random];
            ans = ans->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    //optimal approach
    Node* copyRandomList(Node* head){
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* copyHead = head->next;
        Node* copyCurr = copyHead;
        while (curr) {
            curr->next = curr->next->next;
            if (copyCurr->next) {
                copyCurr->next = copyCurr->next->next;
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};
