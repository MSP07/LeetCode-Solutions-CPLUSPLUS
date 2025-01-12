/*approach
  hashmap, counting
  to make k palindromes we must ensure that the chars present
  either are all even in number or if its odd then k must be greater
  than that odd count. So we first using hashmap count the occurences of
  chars and if its odd then we check whether the odd is less than k*/
class Solution{
public:
    bool canConstruct(string s,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(k>s.size())return false;
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        int odd = 0;
        for(int cnt:freq){
            if(cnt%2){
                odd++;
            }
        }
        return k >= odd;
    }
};
