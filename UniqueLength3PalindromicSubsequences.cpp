/*approach
  prefixsum
  we keep track of the 3 length string and we check 
  whether any string before and after exists by removing
  or adding first and last char in the string and keep count 
  of it before finally returning it*/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>right(26,0);
        for(auto &u : s){
            right[u-'a']++;
        }
        vector<int>left(26, 0);
        unordered_set<int>unique;
        for(int i=0;i<s.length();i++){
            int t = s[i] - 'a';
            right[t]--;
            for(int j = 0; j < 26; j++){
                if(left[j] > 0 && right[j] > 0){
                    unique.insert(26*t + j);
                }
            }
            left[t]++;
        }
        return unique.size();
    }
};
