/*approach
  sorting,greedy
  we use the triangle property a < b+c after sorting the given array
  and return the max one as we iterate from last if nothing satisfies this condition
  we return 0*/
class Solution{
public:
    int largestPerimeter(vector<int>& nums){
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=2;--i){
            if(nums[i]<nums[i-1]+nums[i-2]){
                return nums[i]+nums[i-1]+nums[i-2];
            }
        }
        return 0;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
