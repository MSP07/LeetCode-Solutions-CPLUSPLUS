/*approach
  bit manipulation, backtracking
  this problem will ultimately come down to finding maxOR between elements
  maxOR will be with the whole num in nums now the main grasp is to start from 0
  index and add elements and check whether their OR gives the maxOR is so we increase the
  count we exlpore diff combinations by backtracking and finally return the count*/
class Solution{
private:
    void backtrack(vector<int>& nums,int ind,int currOR,int maxOR,int& count){
        if(currOR == maxOR){
            count++;
        }
        for(int i=ind;i<nums.size();++i){
            backtrack(nums,i+1,currOR|nums[i],maxOR,count);
        }
    }
public:
    int countMaxORSubsets(vector<int>& nums){
        int maxOR = 0;
        for(int num:nums){
            maxOR |= num;
        }
        int count = 0;
        backtrack(nums,0,0,maxOR,count);
        return count;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
