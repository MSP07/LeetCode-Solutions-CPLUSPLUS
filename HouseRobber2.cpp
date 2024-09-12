/*approach
  here we either have to start from 0 go to n-1 or start from 1 and go to n
  and find the same max robbing content we did in House Robber 1 and return it*/
class Solution{
private:
    int street(int start,int end,vector<int>& nums){
        if(end-start==2)return max(nums[start],nums[start+1]);
        int prev2 = nums[start], prev = nums[start+1];
        for(int i=2;i<nums.size();i++){
            int curr = max(prev,prev2+nums[start+i]);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums){
        int n = nums.size();
        if(n==2)return max(nums[0],nums[1]);
        int robWithFirst = street(0,n-1,nums);
        int robWithoutFirst = street(1,n,nums);
        return max(robWithFirst,robWithoutFirst);
    }
};
