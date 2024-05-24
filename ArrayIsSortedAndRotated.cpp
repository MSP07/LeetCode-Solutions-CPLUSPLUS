//approach
//initialise a variable for counting
//is the first element is less than last element we increase the count as this may or may not be possible in a sorted rotated array
//ina a sorted and rotated array there will be only one element where the element will be smaller than the previous element so we check for that conditon and increase the count
//if the count is more than 1 that means the given array is not sorted. if it is sorted the only condition it will satisfy is the above one.
class Solution{
public:
    bool check(vector<int>&nums){
        int cnt = 0;
        int n = nums.size();
        if(nums[0]<nums[n-1])cnt++;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                cnt++;
                if(cnt>1)return false;
            }
        }
        return true;
    }
};
