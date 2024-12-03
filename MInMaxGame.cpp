/*approach
  recursion, simulation
  base case will be if only one element we return that element 
  else we shrink the vector to half of its size and add numbers at the index
  as per whether they are odd or even and follow the given instructions and
  call the same function again and finally return the ans*/
class Solution{
public:
    int minMaxGame(vector<int>& nums){
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>ans(n/2);
        for(int i=0;i<n/2;i++){
            if(i%2){
                ans[i] = max(nums[2*i],nums[2*i+1]);
            }else{
                ans[i] = min(nums[2*i],nums[2*i+1]);
            }
        }
        return minMaxGame(ans);
    }
};
