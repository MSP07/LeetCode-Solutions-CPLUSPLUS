/*approach
  we can solve this using hashmap with 0(2n) time and 0(n)+0(n) space
  we can sort and finish in 0(nlogn) time and 0(n/2) space 
  to complete this problem in 0(n) time and 0(1) + 0(n/2) space we can follow visited approach
  instead of declaring a visited array we simply make the element at the particular ind -nums[i]
  we traverse to nums[ind] where ind = abs(nums[i])-1 and if it is <0 means we have visited it so 
  there is a duplicate and we add it to answer else we simply make it -nums[i] and finally return the vector*/
class Solution{
public:
    vector<int> findDuplicates(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>ans;
        if(nums.size()==1)return ans;
        for(int i=0;i<nums.size();++i){
            int index = abs(nums[i])-1;
            if(nums[index]<0){
                ans.push_back(abs(nums[i]));
            }else{
                nums[index] = -nums[index];
            }
        }
        return ans;
    }
};
