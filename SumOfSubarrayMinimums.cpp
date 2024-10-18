/*approach
  stack
  brute force will be to use two loops but can be reduced
  if we do iteration from left to right store the minimum index values, we do this by popping the
  index if there is an element greater than the element in the prev index and we add the index to left array
  the minimum element from that particular index and we do the same from right to left too. Now we have left and
  right arrays where it indicates the minimum element from that particular index and with that we add their product and return*/
class Solution{
    const int MOD = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr){
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int>s1,s2;
        for(int i=0;i<n;++i){
            while(!s1.empty() && arr[s1.top()] > arr[i]){
                s1.pop();
            }
            left[i] = s1.empty() ? i+1 : i-s1.top();
            s1.push(i);
        }
        for(int i=n-1;i>=0;--i){
            while(!s2.empty() && arr[s2.top()] >= arr[i]){
                s2.pop();
            }
            right[i] = s2.empty() ? n-i : s2.top()-i;
            s2.push(i);
        }
        long long ans;
        for(int i=0;i<n;++i){
            ans = (ans+(long long)arr[i]*left[i]*right[i])%MOD;
        }
        return ans;
    }
};
