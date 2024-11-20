/*approach
  deque, sliding window, prefixSum
  first we store all the prefixSum and start iterating
  we check for the sum from both front and back and update the ans w.r.t the index
  and prefixSum and keep track of the min one. To implement this we use deque
  and finally return the min one, if no min exists we return -1*/
class Solution{
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        vector<long long>prefixSum(n+1,0);
        for(int i=0;i<n;++i){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        int mini = INT_MAX;
        for(int i=0;i<=n;++i){
            while(!dq.empty() && prefixSum[i]-prefixSum[dq.front()]>=k){
                mini = min(mini,i-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && prefixSum[i]<=prefixSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return mini == INT_MAX ? -1 : mini;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
