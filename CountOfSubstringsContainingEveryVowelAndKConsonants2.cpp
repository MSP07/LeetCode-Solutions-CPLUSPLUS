/*approach
  sliding window, hashmap  
  first we start using two diff pointers and if we encounter vowels
  that is not already seen we incr the count of vowels else we incr count of conso
  and if vowels == 5 and conso >= k then we reduce the window size from start pointer
  we do this till the array end and finally return the cnt*/
class Solution {
private:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    long long atleast(string word,int k){
        long long cnt = 0;
        int start = 0, end = 0;
        unordered_map<char,int>hashi;
        int conso  = 0;
        while(end<word.size()){
            char c = word[end];
            if(isVowel(c)){
                hashi[c]++;
            }else{
                conso++;
            }
            while(hashi.size() == 5 && conso >= k){
                cnt += word.size()-end;
                char temp = word[start];
                if(isVowel(temp)){
                    if(--hashi[temp]==0){
                        hashi.erase(temp);
                    }
                }else{
                    conso--;
                }
                start++;
            }
            end++;
        }
        return cnt;
    }
public:
    long long countOfSubstrings(string word, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        return atleast(word,k) - atleast(word,k+1);
    }
};
