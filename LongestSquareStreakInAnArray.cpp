/*approach
  greedy approach using hashmap, can be solved with dp too but more tc should use take, notTake approach
  we first initialise hashmap with all the numbers in nums then iterate through the array if we find a square for curr 
  num in the hashmap then we incr the streak and if the curr values go out of bound then sure there is no next element
  as given no out of bound elements shall be present and it is not possible too. We keep track of the maxStreak of 
  all those streaks and finally return it if the maxStreak >= 2 else we return -1 as per question*/
class Solution{
public:
    int longestSquareStreak(vector<int>& nums){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<int>hashi(nums.begin(),nums.end());
        int maxStreak = 0;
        for(int num:nums){
            int streak = 0;
            long long curr = num;
            while(hashi.count(curr)){
                streak++;
                curr *= curr;
                if(curr>1e5)break;
            }
            maxStreak = max(maxStreak,streak);
        }
        return maxStreak;
    }
};
