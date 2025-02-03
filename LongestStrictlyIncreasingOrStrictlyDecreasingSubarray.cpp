/*approach
  array,counting
  by default the length of increasing and decreasing sequence is 1
  so when we encounter a increasing sequence we assume its strictly increasing and set
  the decr count to one and we do the vice versa when we encounter a decreasing sequence and
  when elements are equal we just reset them to their org count and keep track of max ones 
  and finally return the max one*/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int incr = 1, decr = 1;
        int maxi = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                incr++;
                decr = 1;
            }else if(nums[i]<nums[i-1]){
                decr++;
                incr = 1;
            }else{
                incr = 1;
                decr = 1;
            }
            maxi = max(maxi,max(incr,decr));
        }
        return maxi;
    }
};
