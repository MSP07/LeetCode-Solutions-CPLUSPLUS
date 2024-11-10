/*approach
  bit maipulation, sliding window
  we use left, right pointers to keep track of a window
  and we calculate the OR values inside that window and update the ORval
  while the conditions are met and shrink the window as much as possible
  to get the minimum subarray of the given array and finally return the minLen
  if not possible we return -1*/
class Solution{
public:
    int minimumSubarrayLength(vector<int>& nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<int>bitSet(32,0);
        int currOR = 0, left = 0,minLen = INT_MAX;
        for(int right=0;right<n;right++){
            currOR |= nums[right];
            for(int bit=0;bit<32;bit++){
                if(nums[right]&(1<<bit)){
                    bitSet[bit]++;
                }
            }
            while(left<=right && currOR>=k){
                minLen = min(minLen,right-left+1);
                int newOR = 0;
                for(int bit=0;bit<32;bit++){
                    if(nums[left]&(1<<bit)){
                        bitSet[bit]--;
                    }
                    if(bitSet[bit]>0){
                        newOR |= (1<<bit);
                    }
                }
                currOR = newOR;
                left++;
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};
