/*approach
  linked list
  to solve this efficiently we make use of the fact that this linked list is sorted
  so if there are duplicates they will be adjacent and the adj nodes should be deleted
  so we check for curr.next exists and if curr.val == curr.next.val then we make the node pointers
  curr.next = curr.next.next else we move forward and finally return the modified head*/
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(!head || !head->next)return head;
        ListNode* curr = head;
        while(curr->next){
            if(curr->val == curr->next->val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
}
