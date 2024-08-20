/*approach
  we iterate first and find all the prefixSum of the given vector for pre-requisite
  then we push the indices into stack and get the leftmost and rightmost indices at which the 
  values are min for that particular index and after getting that we iterate over nums again and 
  find the maxProd by taking max between maxProd and sum*nums[i] where sum will be right - left of
  that particular index more preferably prefixSum[right[i]-1] - prefixSum[left[i]] and we return the maxProd*/
class Solution{
    const int mod = 1e9 + 7;
public:
    int maxSumMinProduct(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        vector<long long>prefixSum(n+1,0);
        for(int i=0;i<n;++i){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        vector<int> left(n), right(n);
        stack<int>st;
        for(int i=0;i<n;++i){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;--i){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            right[i] = st.empty() ? n-1 : st.top() - 1;
            st.push(i);
        }
        long long maxProd = 0;
        for(int i=0;i<n;++i){
            long long sum = prefixSum[right[i]-1] - prefixSum[left[i]];
            maxProd = max(maxProd,sum*nums[i]);
        }
        return maxProd % mod;
    }
};
