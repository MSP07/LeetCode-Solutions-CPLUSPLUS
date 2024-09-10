/*approach
  we just start from head node and till there is a head->next we calculate
  gcd for curr node and next node add it in the middle and keep iterating
  after adjusting nodes to their respective positions*/
class Solution{
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(!head || !head->next)return head;
        ListNode* curr;
        while(curr && curr->next){
            int gcdVal = gcd(curr->val,curr->next->val);
            ListNode* newNode = new ListNode(gcdVal);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        return head;
    }
};
