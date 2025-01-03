/*approach
  prefixSum
  since our aim is to find points where leftSum >= rightSum
  first in rightSum we find the total of all elements and then
  starting from left till the last before element we simultaneosuly
  add the element to leftsum and remove it from total and whenever 
  leftsum >= rightsum there is a point so we increase the splits/points
  and finally return it*/
class Solution{
public:
    int waysToSplitArray(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        long long leftSum = 0, rightSum = 0;
        for(int num:nums){
            rightSum += num;
        }
        int splits = 0;
        for(int i=0;i<nums.size()-1;i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            if(leftSum >= rightSum)splits++;
        }
        return splits;
    }
};
