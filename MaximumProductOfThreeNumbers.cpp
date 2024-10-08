/*approach
  sorting
  we sort the given array and to handle the negative numbers we check return the max
  of product of first two and last element or product of last three numbers*/
class Solution{
public:
    int maximumProduct(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[n-1],nums[n-1]*nums[n-2]*nums[n-3]);
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
