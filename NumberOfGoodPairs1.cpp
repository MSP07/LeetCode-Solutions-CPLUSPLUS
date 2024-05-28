//approach
//we simply iterate through the given two arrays and keep a var with second element*k and check whether it is divisible and increase the count
class Solution{
public:
    int numberOfPairs(vector<int>&nums1,vector<int>&nums2,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int ans = 0, div;
        for(auto val1:nums1){
            for(auto val2:nums2){
                div = val2*k;
                if(val1%div==0)ans++;
            }
        }
        return ans;
    }
};
