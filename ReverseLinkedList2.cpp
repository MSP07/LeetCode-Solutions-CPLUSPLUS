/*approach
  revrese linked list approach
  as per given condition since we have to reverse a particular group
  we mark the node before the left node as prev and node after right as ahead
  we reverse the range of nodes and make prev->next = reversedNode and since the leftmost node
  in the range is reversed it will be right before ahead after reversing so start->next = ahead
  and we return the head or the dummy node's next as we taken it as our index*/
class Solution{
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head,int left,int right){
        if(!head or left==right)return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        int cnt = 1;
        while(cnt<left){
            prev = prev->next;
            cnt++;
        }
        ListNode* start = prev->next;
        ListNode* end = start;
        ListNode* ahead = nullptr;
        while(cnt<right){
            end=end->next;
            cnt++;
        }
        ahead = end->next;
        end->next = nullptr;
        ListNode* reversed = reverseList(start);
        prev->next = reversed;
        start->next = ahead;
        return dummy->next;
    }
};
