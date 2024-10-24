/*approach
  linked list
  to do this in constant space
  start by alloting a dummy node to start of head also alloting prev to dummy
  then from head while there is a duplicate val in 
  upcoming nodes we mark there is duplicate and keep moving
  when we stop we connect the prev to the next node so as removing the duplicate nodes part
  else we simply move prev to next node as there are no duplicates in the list*/
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(!head && !head->next)return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(head){
            bool isDuplicate = false;
            while(head->next && head->val==head->next->val){
                isDuplicate = true;
                head = head->next;
            }
            if(isDuplicate){
                prev->next = head->next;
            }else{
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};
