//approach
//reverse the linked list, then keep two pointers with a variable keeping track of max val.
//whenever we see a val greater then max val we update max val and continue traversing
//else if we see a node with less val than max val we skip that node by making prev node attach to next node of the current one(prev->next = curr->next)
//after traversal we again reverse the linked list and return the head

class Solution{
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr!=nullptr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
public:
    ListNode* removeNodes(ListNode* head){
        head = reverseList(head);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int maxi = INT_MIN;
        while(curr!=nullptr){
            if(curr->val>=maxi){
                maxi = curr->val;
                prev = curr;
            }else{
                prev->next = curr->next;
            }
            curr = curr->next;
        }
        return head;
    }
};
