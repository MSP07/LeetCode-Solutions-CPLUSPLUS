/*approach
  we use a comparator function to sort the given strings in the vector
  then we return the [n-k]th element after sorting which will be the kth largest element*/
class Solution{
public:
    const bool comp(string& a,string& b){
        if(a.size()==b.size()){
            return a<b;
        }
        return a.size() < b.size();
    }
    string kthLargestNumber(vector<string>& nums,int k){
        sort(nums.begin(),nums.end(),comp);
        int n = nums.size();
        return nums[n-k];
    }
};
