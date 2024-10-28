/*approach
  sorting
  we sort the given array and iterate till last but one element and check
  diff of all the pairs, keep track of maxDiff and finally return that*/
class Solution{
public:
    int maximumGap(vector<int>& nums){
        if(nums.size()<2)return 0;
        if(nums.size()==2)return abs(nums[0]-nums[1]);
        sort(nums.begin(),nums.end());
        int maxGap = INT_MIN;
        for(int i=0;i<nums.size()-1;++i){
            maxGap = max(maxGap,nums[i+1]-nums[i]);
        }
        return maxGap;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
