/*approach
  to maximise the BITWISE AND the max element of the given array should be present in the array
  so we iterate through the array and if we find continuous of maxElements we increase the len and
  keep the max of the length and finally return the maxLen*/
class Solution{
public:
    int longestSubarray(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int maxElement = *max_element(nums.begin(),nums.end());
        int maxLen = 0;
        int currLen = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==maxElement){
                ++currLen;
                maxLen = max(maxLen,currLen);
            }else{
                currLen = 0;
            }
        }
        return maxLen;
    }
};
