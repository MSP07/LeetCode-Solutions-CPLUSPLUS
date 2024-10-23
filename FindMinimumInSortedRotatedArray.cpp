/*approach
  linear search
  simply iterate and keep track of lowest element
  i have kept 5001 as limit in question was 5000
  recommonded to keep ans as INT_MAX for larger test cases*/
class Solution{
public:
    int findMin(vector<int>& nums){
        int ans = 5001;
        for(int num:nums){
            if(num<ans){
                ans = num;
            }
        }
        return ans;
    }
};
