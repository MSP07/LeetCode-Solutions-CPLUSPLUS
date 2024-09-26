/*approach
  we first nums[i] inside a temp variable until we find a non equivalent element we keep moving i
  when it is not equal we push the element from starting with "->" till nums[i] else we push the 
  temp alone and finally return the ans*/
class Solution{
public:
    vector<string> summaryRanges(vector<int>& nums){
        int n = nums.size();
        vector<string>ans;
        for(int i=0;i<n;++i){
            int temp = nums[i];
            while(i+1<n && nums[i+1]==nums[i]+1){
                i++;
            }
            if(temp!=nums[i]){
                ans.push_back(to_string(temp) + "->" + to_string(nums[i]));
            }else{
                ans.push_back(to_string(temp));
            }
        }
        return ans;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
