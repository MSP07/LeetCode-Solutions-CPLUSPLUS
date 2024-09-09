/*approach
  iterate through ll add values to vector sort it 
  and finally form a ll from that vector and return it*/
class Solution{
public:
    ListNode* sortList(ListNode* head){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>list;
        while(head){
            list.push_back(head->val);
            head = head->next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(int i=0;i<list.size();++i){
            curr->next = new ListNode(list[i]);
            ListNode* front = curr->next;
            curr = front;
        }
        return dummy->next;
    }
};
