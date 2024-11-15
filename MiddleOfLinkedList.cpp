/*approach
  linked list, two pointers
  we start with two pointers pointing to head and one moves one node at a time
  whereas another moves two nodes at a time when the second pointer reaches end the first
  pointer would have reached the middle, this works because one pointer moves twice of other
  and so ensuring in the other one reaching the middle node*/
class Solution{
public:
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
