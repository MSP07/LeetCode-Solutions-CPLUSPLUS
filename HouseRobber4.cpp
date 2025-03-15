/*approach
  binary search
  the capacity is max the robber can steal so left is min element and 
  right is the max element possible then we do binary search we find mid
  if k no of houses can be stolen with mid as target or val we shrink the size to
  left to mid-1 and ans = mid else we shrink the size to mid+1 to right alone
  for checking we iterate through the nums and if nums[i]<=val or nums[i]<=target
  then we skip the adj nums[i] as we cannot steal adj houses and keep a cnt variable
  if cnt == k at any point it is possible we return true else we return false after complete
  iteration and finally return the ans*/
class Solution {
    private:
        bool isPossible(vector<int>& nums,int k,int val){
            int cnt = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<=val){
                    cnt++;
                    i++;
                }
                if(cnt==k)return true;
            }
            return false;
        }
    public:
        int minCapability(vector<int>& nums, int k) {
            int left = *min_element(nums.begin(),nums.end());
            int right = *max_element(nums.begin(),nums.end());
            int ans = right;
            while(left<=right){
                int mid = left + (right-left)/2;
                if(isPossible(nums,k,mid)){
                    ans = mid;
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }
            return ans;
        }
    };
    
    const auto init = [](){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return 0;
    }();
