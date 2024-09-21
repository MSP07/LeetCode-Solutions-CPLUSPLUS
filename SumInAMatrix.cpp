/*approach
  we simply sort every row of matrix first
  then we start from last element in column and iterate
  that column calculate max element add it to score and iterate 
  towards the 0th index and finally return the score*/
class Solution{
public:
    int matrixSum(vector<vector<int>>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int score = 0;
        int n = nums.size();
        for(int i=0;i<n;++i){
            sort(nums[i].begin(),nums[i].end());
        }
        for(int i=nums[0].size()-1;i>=0;i--){
            int maxi = INT_MIN;
            for(int j=0;j<n;++j){
                maxi = max(maxi,nums[j][i]);
            }
            score += maxi;
        }
        return score;
    }
};
