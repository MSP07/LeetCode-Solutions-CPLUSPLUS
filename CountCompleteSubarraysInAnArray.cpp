/*approach
  hashmap,sliding window
  first we calculate total no of disinct using set and 
  we use sliding window technique to find that in the given subarray
  if the distinct elements count match then we take that subarray size since all
  the elements are possible and we decrease the count of left element by this method
  we iterate full array and finally return the count*/
class Solution{
public:
    int countCompleteSubarrays(vector<int>& nums){
        int totalDistinct = unordered_set<int>(nums.begin(),nums.end()).size();
        int left = 0, cnt = 0;
        unordered_map<int,int>hashi;
        for(int right=0;right<nums.size();right++){
            hashi[nums[right]]++;
            while(hashi.size()==totalDistinct){
                cnt += (nums.size()-right);
                hashi[nums[left]]--;
                if(hashi[nums[left]]==0)hashi.erase(nums[left]);
                left++;
            }
        }
        return cnt;
    }
};
