//approach
//we keep two arrays for even and odd 
//we simultaneously update them for each index accordingly
//finally wwe return the max element between the last elements of the given two arrays
class Solution{
public:
    long long maxAlterantingSum(vector<int>&nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        vector<long long>dpEven(n),dpOdd(n);
        dpEven[0] = nums[0];
        dpOdd[0] = 0;
        for(int i=1;i<n;i++){
            dpEven[i] = max(dpEven[i-1],dpOdd[i-1]+nums[i]);
            dpOdd[i] = max(dpOdd[i-1],dpEven[i-1]-nums[i]);
        }
        return max(dpEven[n-1],dpOdd[n-1]);
    }
};
