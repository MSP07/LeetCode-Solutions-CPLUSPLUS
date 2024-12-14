/*approach
  two pointers, deque, sliding window
  we can use two deques to keep track of max element and min element
  in the given window with the sliding window condition max-min <= 2
  we can expand the window from right or j pointer and shrink it in the
  left or i pointer as necessary. For every valid window we incr the count*/
class Solution{
    long long continuousSubarrays(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        deque<int> maxDeque, minDeque;
        long long cnt = 0;
        int i=0;
        for(int j=0;j<n;j++){
            while(!maxDeque.empty() && nums[maxDeque.back()]<=nums[j]){
                maxDeque.pop_back();
            }
            maxDeque.push_back(j);
            while(!minDeque.empty() && nums[minDeque.back()]>=nums[j]){
                minDeque.pop_back();
            }
            minDeque.push_back(j);
            while(nums[maxDeque.front()]-nums[minDeque.front()]>2){
                if(maxDeque.front()==i)maxDeque.pop_front();
                if(minDeque.front()==i)minDeque.pop_front();
                i++;
            }
            cnt += (j-i+1);
        }
        return cnt;
    }
};
