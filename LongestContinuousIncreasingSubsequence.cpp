/*approach
  array traversal
  we traverse from first element checking if curr element is greater than prev element
  if so incr the len else if len > maxLen that we assumed as 1 first then we update maxLen to len and 
  update len to 1 else make len =1 indiacting same elements and one final check for maxLen and update it
  and finally return the maxLen*/
class Solution{
public:
    int findLengthOfLCS(vector<int>& nums){
        int len=1,maxLen=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1])len++;
            else if(len>maxLen){
                maxLen = len;
                len = 1;
            }else{
                len = 1;
            }
        }
        if(len>maxLen)maxLen = len;
        return maxLen;
    }
};
