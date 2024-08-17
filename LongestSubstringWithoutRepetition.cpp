/*approach
  sliding window and hash map
  while iterating through the string we keep track of chars
  if the char is new we update the maxLength accordingly to that
  else if that charCount.count is 1 already then we erase/shrink the window
  till the charCount becomes 0 and we keep iterating till end of the string and
  finally return the maxLength*/
class Solution{
public:
    int lenghtofLongestSubstring(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = s.size();
        int left = 0, maxLength = 0;
        unordered_map<char,int>charCount;
        for(int right=0;right<n;++right){
            if(charCount.count[s[right]]==0){
                charCount.insert(s[right]);
                maxLength = max(maxLength,right-left+1);
            }else{
                while(charCount.count[s[right]]){
                    charCount.erase(s[left]);
                    ++left;
                }
                charCount.insert(s[right]);
            }
        }
        return maxLength;
    }
};
