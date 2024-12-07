/*approach
  binary search
  we can perform binary search to find ceil and add appropriate 
  nums that can be divided and then update the pointers left,right
  that are initially in 1 and max_element respectively, we also update
  the ans with mid as this can be the highest min element possible
  and after iteration we finally return it giving us a optimal solution*/
class Solution{
public:
    int minimumSize(vector<int>& nums,int maxOperations){
        int left=1,right=*max_element(nums.begin(),nums.end());
        int ans = right;
        while(left<=right){
            int mid = left + (right-left)/2;
            int operations = 0;
            for(int num:nums){
                operations += (num-1)/mid;
            }
            if(operations<=maxOperations){
                ans = mid;
                right=mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};
