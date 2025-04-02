/*approach
  array
  we keep one num and with that we track other two keep track of max
  one and finally return it*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long y = 0, x = 0, ans = 0;
        for(int num:nums){
            ans = max(ans,x*num);
            x = max(y-num,x);
            y = max(y,(long long)num);
        }
        return ans;
    }
};
