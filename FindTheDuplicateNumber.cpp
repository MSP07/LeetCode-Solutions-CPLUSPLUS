/*approach
  finding intersection point in linked list approach
  similar to linked list we have two pointers slow and fast and we initailise them to nums[0]
  we consider indices to be node and the nums[index] to be its value and we move slow and fast similarly as in ll
  but to the value of nums[slow] when both meet we initialise slow again to nums[0] and move again till both of them meet
  and return either of them this give 0(1) space approach*/
class Solution{
public:
    int findDuplicate(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0]
        while(slow != fast){
            slow = nums[slow]
            fast = nums[fast]
        }
        return slow;
    }
};
