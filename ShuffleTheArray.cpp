/*approach
  two pointers one at starting and other at i + n
  iteratively push element at first pointer and element at second pointer
  goes on till first pointer reaches n (half of the given array)
  then return the data structure where elements are pushed*/
class Solution{
public:
    vector<int> shuffle(vector<int>& nums,int n){
        vector<int>ans;
        int i = 0, j = i + n;
        while(i<n){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans;
    }
};
