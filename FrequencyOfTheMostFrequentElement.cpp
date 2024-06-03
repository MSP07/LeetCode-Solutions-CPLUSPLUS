//approach
//two pointer sliding window approach
//we keep track of total so far whenever the nums[i]*postion(right-left+1) is higher than total+k we shrink the window'
//we keep track of max position as count
//we finally return the cnt or ans
class Solution{
public:
    int maxFrequency(vector<int>&nums,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        sort(nums.begin(),nums.end());
        int left = 0, ans = 1;
        long long total = 0;
        for(int right=0;right<nums.size();right++){
            total += nums[right];
            while((long long)nums[right]*(right-left+1)>total+k){
                total -= nums[left];
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
