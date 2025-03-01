/*approach
  array, simulation
  we keep a pointer at nums and iterate it two times
  first time we add the even num to even indices
  second time we add the odd num to odd indices
  finally returning the ans array*/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>ans(nums.size(),0);
        int i = 0;
        for(int num:nums){
            if(num%2==0){
                ans[i] = num;
                i += 2;
            }
        }
        i = 1;
        for(int num:nums){
            if(num%2){
                ans[i] = num;
                i += 2;
            }
        }
        return ans;
    }
};
