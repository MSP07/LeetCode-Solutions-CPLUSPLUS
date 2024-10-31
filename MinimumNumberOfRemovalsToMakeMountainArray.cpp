/*approach
  dp - tabuulation
  mountain array when analyzed closely is nothing but a botonic sequence
  which means having both increasing and decreasing subsequence to find that
  we simply run both LIS(longest increasing subsequence) and LDS(longest decreasing subsequence)
  and to make the given array biotonic we simply need to find the longest biotonic seqeunce and 
  subtract the length of given array from that*/
class Solution{
public:
    int minimumMountainRemovals(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<int>LIS(n,1), LDS(n,1);
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j] && LIS[i]<LIS[j]+1){
                    LIS[i] = LIS[j] + 1;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j] && LDS[i]<LDS[j]+1){
                    LDS[i] = LDS[j]+1;
                }
            }
        }
        int maxBiotonic = 0;
        for(int i=1;i<n-1;++i){
            if(LIS[i]>1 && LDS[i]>1){
                maxBiotonic = max(maxBiotonic,LIS[i]+LDS[i]-1);
            }
        }
        return maxBiotonic;
    }
};
