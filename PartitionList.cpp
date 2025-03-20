/*approach
  Linked List, Two Pointers
  to save space we will use pointers to manipulate in the nodes given
  we will have less_head, less_tail and greater_tail, greater_head 
  if head->val < x then we keep less_tail->next = head and less_tail = head
  vice versa for head->val>=x greater_tail->next = head and greater_tail=head
  now finally we point greater_tail->next = nullptr to complete the linked list
  then initially we have kept less_head and greater_head for pointing purpose
  less_tail->next = greater_head->next so as to join the less elements to greater elements than x
  finally we return less_head->next as the starting*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head = new ListNode(0), *greater_head = new ListNode(0);
        ListNode* less_tail = less_head, *greater_tail = greater_head;
        while(head){
            if(head->val<x){
                less_tail->next = head;
                less_tail = head;
            }else{
                greater_tail->next = head;
                greater_tail = head;
            }
            head = head->next;
        }
        greater_tail->next = nullptr;
        less_tail->next = greater_head->next;
        return less_head->next;
    }
};
