/*approach
  simple iteration
  since first node is 0 we keep dummy pointer/node at second node and start
  we keep another pointer/node for summing up values then we iterate till end
  till we reach another node with 0 we sum the values and when we reach the node 
  with 0 we add the sum to dummy node and continue the iteration and point the dummy
  node to next node of the second node*/
class Solution{
public:
    ListNode* mergeNodes(ListNode* head){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        ListNode* modify = head->next;
        ListNode* nextSum = modify;
        while(nextSum!=nullptr){
            int sum = 0;
            while(nextSum->val!=0){
                sum += nextSum->val;
                nextSum = nextSum->next;
            }
            modify->val = sum;
            nextSum = nextSum->next;
            modify->next = nextSum;
            modify = modify->next;
        }
    }
};
