/*approach
  sorting three pointers
  we sort the array initalily take closest sum as sum of first 3 elements
  then keeping i and iterating through the array we keep left as i+1 and right as lat index
  with that we calculate whether their sum is equal to target and return , we update the closest sum
  if current sum is near to target i.e. abs(currsum-target)<abs(closestsum-taarget) then closestsum = currsum
  also we update left and right pointers accordingly if currsum is less than target then left++ if currsum is
  greater then right-- and finally return the closestsum*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        for(int i=0;i<n-2;++i){
            int left = i+1;
            int right = n-1;
            while(left<right){
                int currSum = nums[i] + nums[left] + nums[right];
                if(currSum==target)return currSum;
                if(abs(currSum-target) < abs(closestSum-target)){
                    closestSum = currSum;
                }
                if(currSum<target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return closestSum;
    }
};
