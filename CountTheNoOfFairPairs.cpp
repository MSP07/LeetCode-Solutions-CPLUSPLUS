/*approach
  sorting, binary search, two pointers
  as per the given question we should find the lower bound that is possible in the
  nums after sorting with upper+1 and lower as targets and the diff in their lower bounds is the ans
  we use two pointers approach to find lb if nums[left]+nums[right] < target then the indices that comes
  in between them all are fairPairs so ans += (right-left) and left++ to check for more pairs else right-- 
  to shrink the window and when left>=right we end the loop and return the ans*/ 
class Solution{
private:
    long long lb(vector<int>& nums,int target){
        int left = 0,right = nums.size()-1;
        int fairPairs = 0;
        while(left<right){
            if(nums[left]+nums[right]<target){
                fairPairs += (right-left);
                left++;
            }else{
                right--;
            }
        }
        return fairPairs;
    }
public:
    long long countFairPairs(vector<int>& nums,int lower,int upper){
        sort(nums.begin(),nums.end());
        return lb(nums,upper+1) - lb(nums,lower);
    }
};
