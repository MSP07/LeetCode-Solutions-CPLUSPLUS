/*approach
  string, string matching
  we check whether any of word in words start with prefix
  keep a count and return it*/
class Solution{
public:
    int prefixCount(vector<string>& words,string pref){
        int cnt = 0;
        int n = pref.size();
        for(string word:words){
            if(word.substr(0,n)==pref)cnt++;
        }
        return cnt;
    }
};
