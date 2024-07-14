/*approach
  we store every element in nums
  we initially create a dummy node and keep a pointer at dummy node
  then we traverse through the given linked list and find whether the 
  value of that linked list is not there in the set if not there we make
  that as new linked list and point the pointer's next to that created linked list
  and we move the pointer forward and by default we move head to next linked list
  whether we did not find that value in set or not and finally return dummy->next
  as dummy is pointing in nullptr*/
class Solution{
public:
    ListNode* modifiedList(vector<int> &nums,ListNode* head){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<int> numSet(nums.begin(),nums.end());
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        while(head!=nullptr){
            if(numSet.find(head->val)==numSet.end()){
                current->next = new ListNode(head->val);
                current = current->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};
