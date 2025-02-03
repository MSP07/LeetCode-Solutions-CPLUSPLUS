/*approach
  array
  we simply calculate the total sum of elements and 
  element sum or the digit sum of all elements in the array
  using divisor and modulo method and finally return the abs between them*/
class Solution {
private:
    int diff(vector<int>& nums){
        int ans = 0;
        for(int num:nums){
            while(num>0){
                ans += num%10;
                num /= 10;
            }
        }
        return ans;
    }
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        return abs(sum-diff(nums));
    }
};
