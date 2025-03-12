/*approach
  linear,binary search
  we simply keep count of no of positive and negative elements
  and return the max among them*/
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cnt1 = 0,cnt2 = 0;
        for(int num:nums){
            if(num>0)cnt1++;
            else if(num<0)cnt2++;
        }
        return max(cnt1,cnt2);
    }
};
