/*approach
   We start with miss set to 1, added to 0, and index i at 0 to track the smallest sum that cannot be formed and the number of patches added.
   Continue the loop as long as miss (the target sum we need to achieve) is less than or equal to n.Check if the current number in the list (nums[i]) can be used to form miss.
   If yes, add it to miss to extend the range of formable sums and increment the index i.If nums[i] is greater than miss or all numbers are already used, add miss itself to cover the smallest 
   unformable sum, and double the value of miss.Whenever a number is added to cover a gap, increase the added counter.Once miss exceeds n, return the total count of added numbers as the result, 
   representing the minimum patches needed to form every number up to n*/
class Solution{
public:
    int minPatches(vector<int>& nums, int n){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long miss = 1;
        int res= 0 ;
        size_t i = 0;
        while(miss<=n){
            if(i<nums.size() && nums[i]<=miss){
                miss += nums[i];
                ++i;
            }else{
                miss += miss;
                ++res;
            }
        }
        return res;
    }
};
