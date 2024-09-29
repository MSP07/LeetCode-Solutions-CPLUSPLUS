/*approach
  hashmap
  first we calculate the highest degree, firstoccurences of elements and last occurences of elements
  all in a single traversal and store in a hashmap then we iterate through the hashmap then calculate
  the min length with the help of first last occurences lastoccurence[i] - firstoccurence[i] + 1 will be
  the subarray size and we take min of all of them*/
class Solution{
public:
    int findShortestSubarray(vector<int>& nums){
        unordered_map<int,int>freq,firstOccur,lastOccur;
        int degree = 0;
        for(int i=0;i<nums.size();++i){
            if(firstOccur.find(nums[i])==firstOccur.end()){
                firstOccur[nums[i]] = i;
            }
            lastOccur[nums[i]] = i;
            freq[nums[i]]++;
            degree = max(degree,freq[nums[i]]);
        }
        int minLen = nums.size();
        for(auto it:freq){
            int num = it.first;
            if(freq[num]==it.second){
                int len = lastOccur[num] - firstOccur[num] + 1;
                minLen = min(minLen,len);
            }
        }
        return minLen;
    }
};
