/*approach
  sliding window
  first sum of k elements then shrink the window and keep the max val
  by adding the curr element from k index and simulatneously removing 
  the first indices one by one and finally returning the max Avg val(maxSum/k)*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;
        for(int i=0;i<k;++i){
            currSum += nums[i];
        }
        maxSum = currSum;
        for(int i=k;i<nums.size();++i){
            currSum += nums[i] - nums[i-k];
            maxSum = max(maxSum,currSum);
        }
        return maxSum/k;
    }
};
