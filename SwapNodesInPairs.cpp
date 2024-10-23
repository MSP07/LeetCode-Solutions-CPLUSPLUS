/*approach
  recursion
  first and second nodes are marked then the next of second will be
  the next of first and second->next = first we recursively do this and
  finally return the second pointed node as that will be the first one here*/
class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        if(!head||!head->next)return head;
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }
};
