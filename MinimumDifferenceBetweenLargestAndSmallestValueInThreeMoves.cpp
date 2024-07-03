/*approach
  we sort the given array
  since we are allowed to make 3 moves that make the n-4th element as new largest
  we subtract that with nums[0] which is the smallest element other than these the other 3 combos
  will be n-3 and 1st , n-2 and 2nd, n-3 and 3rd element and we return min of all these four*/
class Solution{
public:
    int minDifference(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int option1 = nums[n-4] - nums[0];
        int option2 = nums[n-3] - nums[1];
        int option3 = nums[n-2] - nums[2];
        int option4 = nums[n-3] - nums[3];
        return min({option1,option2,option3,option4});
    }
};
