/*approach
  two pointers approach
  we use the same method as finding middle node in linked list we make
  one pointer (slow) move one node at a time and another (fast) moving two nodes
  at a time and if they meet then there is a intersection point, this works because
  slow will check the nodes fast as left and will eventually meet, if they do not meet
  then there is no intersection*/
class Solution{
public:
    bool hasCycle(ListNode* head,int pos){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
};
