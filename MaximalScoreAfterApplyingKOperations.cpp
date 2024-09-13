/*approach
  greedy
  we use priority queue to store top val and maipulate the top value
  as per given conditions and change val accordingly and finally return
  the val*/
class Solution{
public:
    long long maxeElements(vector<int>& nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<int>pq;
        for(auto num:nums){
            pq.push(num);
        }
        long long ans = 0, val;
        while(k--){
            val = pq.top();
            pq.pop();
            ans += val;
            pq.push(ceil(double(val/3.0)));
        }
        return ans;
    }
};
