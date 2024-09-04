/*approach
  we first swap places inside the array such that all positive are in sorted way that is
  nums[0] = 1, nums[1] = 2 and so on.... to do that we simply check whether nums[i] != i+1
  and swap them and we also ensure that no two elements are adjacent nums[i] != nums[nums[i]-1]
  if so then no point in swapping and we iterate again in the same array and the first number in the 
  vector that is not positive or nums[i] != i+1 then we return that i+1 as that will be our missing positive
  if not found then n+1 will be the missing positive example cases for this [1,2,3]*/
class Solution{
public:
    int firstMissingPositive(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        for(int i=0;i<n;++i){
            while(nums[i]>0 && nums[i]<n && nums[i]!=i+1 && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
