/*approach
  we sort the given array 
  we keep a temp variable that keeps curr nums[i] and if we find curr ele - 1is prev element
  there is a consecutive sequence so we increase the count else we keep the count to 1 and keep
  track of max value of cnt and return it*/
class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        if(n<=1)return n;
        sort(nums.begin(),nums.end());
        int longest = 0, cnt = 0, small = INT_MAX;
        for(int i=0;i<n;++i){
            if(nums[i]-1==small){
                cnt += 1;
                small = nums[i];
            }else if(nums[i]!=small){
                cnt = 1;
                small = nums[i];
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
};
