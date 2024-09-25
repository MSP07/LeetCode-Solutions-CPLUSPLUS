/*approach
  brute force will be to get values of linked list sort them then create new linked list
  with sorted linked lists and return the head of that
  better soln will be to use min heap
  where we do not use extra space and we simply put the min element in the first and 
  the next smallest to the next of it by this we do not take any extra space and can solve
  the problem in nlogk TC n - nodes, k -no of groups
  optimal soln :
  we first take all linked list inside an array or vector 
  we write a comparator function we sort the linked lists in the ll form
  we connect the soted linked lists and connect the last linked list to nullptr and 
   return ans[0] as the head
  */
optimal approach
class Solution {
public:
    static bool compare(ListNode* a,ListNode* b){
        return a->val < b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>ans;
        for(auto list:lists){
            ListNode* curr = list;
            while(curr){
                ans.push_back(curr);
                curr = curr->next;
            }
        }
        if(ans.empty())return nullptr;
        sort(ans.begin(),ans.end(),compare);
        for(int i=0;i<ans.size()-1;++i){
            ans[i]->next = ans[i+1];
        }
        ans.back()->next = nullptr;
        return ans[0];
    }
};

better approach
class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top(); 
            minHeap.pop();
            curr->next = smallest; 
            curr = curr->next;
            
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy->next;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
