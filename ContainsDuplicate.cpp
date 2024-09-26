/*approach
  greedy
  sort the array and if we find two consecutive elements then they are repeated 
  so we return true else we return false*/
class Solution{
public:
    bool containsDuplicate(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==nums[i+1])return true;
        }
        return false;
    }
};
