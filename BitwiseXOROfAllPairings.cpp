/*approach
  bit manipulation
  we first initialise variable with two xor's starting with 0
  we just xor the array that is odd in length since even
  length would result in same which when xor'ed will give 0
  and finally xor the two xor's and return them*/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1=0,xor2=0;
        int len1 = nums1.size(),len2 = nums2.size();
        if (len2 % 2 != 0) {
            for (int num : nums1) {
                xor1 ^= num;
            }
        }
        if (len1 % 2 != 0) {
            for (int num : nums2) {
                xor2 ^= num;
            }
        }
        return xor1 ^ xor2;
    }
};
