/*approach
  we use bitmask approach
  The key observation is that the same bitmask appearing multiple times means
  that the substring between those two appearances has even counts for all vowels.
  so we use hashmap to track the parity of the vowel if even then we take that substring as maxLen
  else we update that bitMask to be found in the particular index*/
class Solution{
public:
    int findTheLongestSubstring(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<int,int>firstOccurence;
        firstOccurence[0] = -1;
        int bitMask = 0, maxLen = 0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='a') bitMask ^= (1 << 0);
            else if(s[i]=='e') bitMask ^= (1 << 1);
            else if(s[i]=='i') bitMask ^= (1 << 2);
            else if(s[i]=='o') bitMask ^= (1 << 3);
            else if(s[i]=='u') bitMask ^= (1 << 4);

            if(firstOccurence.find(bitMask)!=firstOccurence.end()){
                maxLen = max(maxLen,i-firstOccurence[bitMask]);
            }else{
                firstOccurence[bitMask] = i;
            }
        }
        return maxLen;
    }
};
