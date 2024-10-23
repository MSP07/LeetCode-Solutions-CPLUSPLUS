/*approach
  linked list, two pointers
  we first traverse and add all the nodes into a vector then if looked closely
  the given condition only requires to iteratively match the nodes which can be done
  by two pointers one at first and another at last and connecting them left to right
  and right to left next by next keeping a bool and starting from left to right and finally
  connecting the last node to null*/
class Solution{
public:
    void reorderList(ListNode* head){
        vector<ListNode*>temp;
        while(head){
            temp.push_back(head);
            head = head->next;
        }
        int left = 0, right = temp.size()-1;
        bool ltr = true;
        while(left<right){
            if(ltr){
                temp[left]->next = temp[right];
                left++;
            }else{
                temp[right]->next = temp[left];
                right -= 1;
            }
            ltr = !ltr;
        }
        temp[left]->next = nullptr;
    }
};
