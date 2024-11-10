/*approach
  array
  find the largest element in the array and its index
  iterate through the array other than the largest element if any element 2*nums[i] > max element we return -1
  after full iteration of the array if no such elements exists then we return the index of that max element*/
class Solution{
public:
    int dominantIndex(vector<int>& nums){
        int maxi = *max_element(nums.begin(),nums.end());
        int maxInd = find(nums.begin(),nums.end(),maxi)-nums.begin();
        for(int i=0;i<nums.size();++i){
            if(i!=maxInd && maxi<2*nums[i])return -1;
        }
        return maxInd;
    }
};
