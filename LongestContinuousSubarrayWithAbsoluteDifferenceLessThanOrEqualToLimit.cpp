/*approach
  we use deque to push the numbers and pop them if it goes off the limit while 
  shrinking the iterating window and updating with max of the length and finally
  returning it*/
class Solution{
public:
    int longestSubarray(vector<int>& nums,int limit){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        deque<int> decQ;
        deque<int> incQ;
        int ans = 0;
        int left = 0;
        for(int right=0;right<nums.size();++right){
            int num = nums[right];
            if(!decQ.empty() && num > decQ.back()){
                decQ.pop_back();
            }
            decQ.push_back(num);
            if(!incQ.empty() && num < incQ.back()){
                incQ.pop_back();
            }
            incQ.push_back(num);
            while(decQ.front() - incQ.front() > limit){
                if(decQ.front()==nums[left]){
                    decQ.pop_front();
                }
                if(incQ.front()==nums[left]){
                    incQ.pop_front();
                }
                ++left;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
