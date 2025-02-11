/*approach
  hashmap
  instead of counting bad pairs which are j-i != nums[j]-nums[i[
  for optimality purpose we count the good pairs that are j-i = nums[j]-nums[i]
  which can be written as nums[i]-i = nums[j]-j and finally subtract them from
  from the total number of pairs possible which is n*(n-1)/2. for every nums[i]
  we calculate nums[i]-i and the count that we have stored in hashmap we increase the
  goodpair count by that much times and by default increase the count of that key in hashmap
  and finally return total-good*/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int, long long> freq;
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2; 
        long long goodPairs = 0;
        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            if (freq.count(key)) {
                goodPairs += freq[key];
            }
            freq[key]++; 
        }
        return totalPairs - goodPairs; 
    }
};
