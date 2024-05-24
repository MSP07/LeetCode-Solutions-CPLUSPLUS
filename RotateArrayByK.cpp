//approach
//reverse the whole array
//reverse the first k elements
//and then reverse the remaining the k elements
class Solution{
public:
    void rotate(vector<int>&nums,int k){
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
