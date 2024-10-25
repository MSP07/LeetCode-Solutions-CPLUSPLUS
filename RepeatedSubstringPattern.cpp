/*approach
  string
  we take substring of size such that if the substring is put multiple times it
  can get the size of given string then we start by taking taking substring and adding it up
  if at any point the addition of all those substrings gives us the org string we return true else false*/
class Solution{
public:
    bool repeatedSubstringPattern(string s){
        int n = s.size();
        for(int i=1;i<=n/2;++i){
            if(n%i==0){
                int times = n/i;
                string substring = s.substr(0,i);
                string temp = "";
                while(times--){
                    temp += substring;
                }
                if(temp == s)return true;
            }
        }
        return false;
    }
};
