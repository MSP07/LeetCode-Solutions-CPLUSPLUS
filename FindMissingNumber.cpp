//approach
//find the sum of given first n numbers
//find sum of given numbers
//subtract them both to get the missing number
class Solution{
public:
    int missingNumber(vector<int>&nums){
        int n = nums.size();
        int ans = (n*(n+1))/2;
        int given = accumulate(nums.begin(),nums.end(),0);
        int soln = ans - given;
        return soln;
    }
};
