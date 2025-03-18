/*approach
  bit manipulation, sliding window
  first we have used = 0, we start and from left =0 
  while used^nums[right] != 0, we perform ans with used ^= nums[left]
  shrink it to left,right then used |= nums[right] and update max with max(maxi,right-left+1)
  finally return the maxi*/
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used = 0, left = 0,maxi = 0;
        for(int right=0;right<nums.size();++right){
            while((used&nums[right])!=0){
                used ^= nums[left];
                left++;
            }
            used |= nums[right];
            maxi = max(maxi,right-left+1);
        }
        return maxi;
    }
};
