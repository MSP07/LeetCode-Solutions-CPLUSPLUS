/*approach
  keep track of all elements in the given array
  if an element is already there in the array we increase the count and finally return it*/
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>cars(101,0);
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            int start = nums[i][0];
            int end = nums[i][1];
            for(int j=start;j<=end;++j){
                cars[j]++;
            }
        }
        for(auto car:cars){
            if(car>0)ans++;
        }
        return ans;
    }
};
