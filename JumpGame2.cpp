/*approach
  greedy algorithm
  we start of by calc the furthest point we can reach from that index
  if we reached the end that we initialised first means we can reaach there 
  with a 1+jump grom prev jump so we do that and we update the curr_end to furthest
  we can reach from curr index as we can do that also in a single jump*/
class Solution{
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        int jumps = 0, curr_end = 0, furthest = 0;
        for(int i=1;i<n-1;++i){
            furthest = max(furthest,i+nums[i]);
            if(i==curr_end){
                jumps++;
                curr_end = furthest;
            }
        }
        return jumps;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
