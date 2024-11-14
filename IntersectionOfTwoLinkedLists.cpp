/*approach
  linked list
  we keep two pointers one at headA and another at headB we iterate on one node at 
  a time in both pointers at any point both nodes are equal that is the intersection point
  else if either of them reaches the end we switch their places like is pointer1 reaches null
  we make pointer1 = headB and vice versa this approach works because this handles the case for
  every linked list length*/
class Solution{
public:
    ListNode* getIntersectionNode(ListNode* headA,ListNode* headB){
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        while(curr1!=curr2){
            curr1 = curr1->next;
            curr2 = curr2->next;
            if(curr1==curr2)return curr1;
            if(curr1==nullptr)curr1 = headB;
            if(curr2==nullptr)curr2 = headA;
        }
        return curr2;
    }
};
