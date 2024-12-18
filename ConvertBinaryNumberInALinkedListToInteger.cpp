/*approach
  linked list, string
  first we iterate and get all the nums in the linked list
  then finally we return that as integer to the power 2*/
class Solution{
public:
    int getDecimalValue(ListNode* head){
        if(!head->next)return head->val;
        string ans = "";
        while(head){
            ans += (head->val+'0');
            head = head->next;
        }
        return stoi(ans,nullptr,2);
    }
};
