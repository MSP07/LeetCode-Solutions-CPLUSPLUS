/*approach
  this can be done in n^2 TC using nested for loops and considering each k subarray and calculating max element from that
  to do this in 0(n) we need a ds which allows us to pop and push both front and back so we can go with deque which allows both
  we push the indices and if the indices go out of bound of k we pop it in front and then compare elements in the back
  and make sure to push the max ele back and add that to our ans and finally return the ans*/
class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();++i){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            if(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
