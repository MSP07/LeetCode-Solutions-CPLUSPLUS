/*approach
  bit manipulation
  initalise maxXorr to 2 pow maxBit - 1 and xorr to first element
  then start iterating from 2nd element and take xor of all elements
  and in ans we store the XOR of xorr and maxXorr while updating xorr
  in the reverse order and finally returning the ans*/
class Solution{
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int xorr = nums[0], maxXorr = pow(2,maximumBit)-1;
        for(int i=1;i<n;++i){
            xorr ^= nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;++i){
            ans[i] = xorr^maxXorr;
            xorr ^= nums[n-1-i];
        }
        return ans;
    }
};
