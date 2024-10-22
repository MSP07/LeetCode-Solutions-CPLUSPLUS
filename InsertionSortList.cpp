/*approach
  insertion sort on given linked list*/
class Solution{
public:
    ListNode* insertionSortList(ListNode* head){
        //normal sorting using extra space
        vector<int>temp;
        ListNode* curr = head;
        while(curr){
            temp.push_back(curr->val);
            curr = curr->next;
        }
        curr = head;
        int i = 0;
        while(i<temp.size() && curr){
            curr->val = temp[i];
            i++;
            curr = curr->next;
        }
        return head;
        //insertion sorting using 0(1) space
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);  
        dummy->next = head;
        ListNode* curr = head->next; 
        head->next = nullptr; 
        while (curr) {
            ListNode* prev = dummy;
            ListNode* nextNode = curr->next;  
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
            curr = nextNode;
        }
        return dummy->next;
    }
};
