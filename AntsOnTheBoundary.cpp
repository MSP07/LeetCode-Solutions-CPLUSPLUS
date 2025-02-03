/*approach
  array,counting
  ants reach the boundary when the sum of all the elements
  till that particular index is 0 so we sum up the elements
  while iterating and whenever sum is 0 it has reached boundary
  so we increase the cnt and finally return it*/
class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cnt = 0, temp = 0;
        for(int num:nums){
            temp += num;
            if(temp==0)cnt++;
        }
        return cnt;
    }
};
