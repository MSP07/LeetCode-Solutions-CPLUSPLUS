/*approach
  array
  we simply add 2 if the curr and last elements are equal else if their
  diff is 1 we add 1 and finally return the ans*/
class Solution{
public:
    int countValidSelections(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>temp(nums.size()+1);
        partial_sum(begin(nums),end(nums),begin(temp)+1);
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(temp.back()==2*temp[i]){
                    ans += 2;
                }else if(temp.back()-2*temp[i]==1){
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
