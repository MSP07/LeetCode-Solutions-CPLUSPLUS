//approach
//sort the given array
//if the sum of first two is less than or equal to the third(highest element) then no traingle can be formed
//if all elements qual equilateral
//if only one pair is equal then it is isosceles
//else it will be scalene
class Solution{
public:
    string TriangleType(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1]<=nums[2])return "none";
        if(nums[0]==nums[1] && nums[1]==nums[2])return "equilateral";
        else if(nums[0]==nums[1] || nums[1]==nums[2])return "isosceles";
        else return "scalene";
    }
};
