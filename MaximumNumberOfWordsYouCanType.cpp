/*approach
  string, hashmap
  we use stringstream and hashset to store brokenletters
  if we find that broken letters in any words we count that
  word and finally return it*/
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>hashi(brokenLetters.begin(),brokenLetters.end());
        stringstream ss(text);
        string word;
        int cnt = 0;
        while(ss>>word){
            bool cantype = true;
            for(char c:word){
                if(hashi.count(c)){
                    cantype = false;
                    break;
                }
            }
            if(cantype)cnt++;
        }
        return cnt;
    }
};
