/*approach
  dp
  as per given condition in the question and to find the abs sum
  we need a combination of both kadane's maxSum and minSum approach
  so we implement that and find the max absolute sum of any subarray*/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minSum = 0, maxSum = 0, minSoFar = 0, maxSoFar = 0;
        for(int num:nums){
            minSum = min(num,minSum+num);
            minSoFar = min(minSoFar,minSum);
            maxSum = max(num,num+maxSum);
            maxSoFar = max(maxSum,maxSoFar);
        }
        return max(abs(minSoFar),abs(maxSoFar));
    }
};
