/*approach
  array
  with respect to num in nums we calculate x and y 
  and we keep track of x and y such that it handles the given condition
  and finally return the ans*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long y = 0, x = 0, ans = 0;
        for(int num:nums){
            ans = max(ans,x*num);
            x = max(x,y-num);
            y = max(y,(long long)num);
        }
        return ans;
    }
};
