/*approach
  sliding window, dp
  We calculate all subarray sums of size k using a sliding window technique.
  left[i]: Tracks the index of the best subarray (maximum sum) from index 0 to i.
  right[i]: Tracks the index of the best subarray (maximum sum) from indexi to the end.
  For each possible middle subarray, use the precomputed left and right indices to calculate
  the total sum of three non-overlapping subarrays*/
class Solution{
public:
    vector<int> maxSumofThreeSubarrays(vector<int>& nums,int k){
        int n = nums.size();
        vector<int>subarray_sum(n-k+1,0);
        int curr_sum = accumulate(nums.begin(),nums.end(),0);
        subarray_sum[0] = curr_sum;
        for(int i=1;i<=n-k;i++){
            curr_sum += nums[i+k-1]-nums[i-1];
            subarray_sum[i] = curr_sum;
        }
        vector<int>left(n-k+1,0),right(n-k+1,0);
        int best_left = 0;
        for(int i=0;i<=n-k;i++){
            if(subarray_sum[i]>subarray_sum[best_left]){
                best_left = i;
            }
            left[i] = best_left;
        }
        int best_right = n-k;
        for(int i=n-k;i>=0;i--){
            if(subarray_sum[i]>=subarray_sum[best_right]){
                best_right = i;
            }
            right[i] = best_right;
        }
        int max_sum = 0;
        vector<int>result(3,0);
        for(int mid=k;mid<=n-2*k;mid++){
            int l = left[mid-k];
            int r = right[mid+k];
            int total = subarray_sum[l]+subarray_sum[mid]+subarray_sum[r];
            if(total>max_sum){
                max_sum = total;
                result = {l,mid,r};
            }
        }
        return result;
    }
};
