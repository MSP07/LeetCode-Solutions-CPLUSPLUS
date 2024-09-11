/*approach
  in brute force first we push all node vals into a vector reverse it in k groups then create a new ll from that
  in optimal we do reversal with the given ll with help of curr pointed to head, prev pointed before head and next
  pointed ahead head in k groups with help of count and return the linked list*/
class Solution{
public:
    //brute force with extra space
    ListNode* reverseKGroup(ListNode* head,int k){
        vector<int>temp;
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }   
        for(int i=0;i+k<=temp.size();i+=k){
            reverse(temp.begin()+i,temp.begin()+i+k);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for(int i=0;i<temp.size();++i){
            curr->next = new ListNode(temp[i]);
            curr = curr->next;
        }
        return dummy->next;
    }
    //optimal approach
    ListNode* reverseKgroup(ListNode* head,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        ListNode* curr = head;
        int count = 0;
        while(curr!=nullptr && count<k){
            curr = curr->next;
            count++;
        }
        if(count==k){
            curr = head;
            ListNode* next = nullptr, *prev = nullptr;
            for(int i=0;i<k;++i){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if(next != nullptr){
                head->next = reverseKgroup(next,k);
            }
            return prev;
        }
        return head;
    }
};
