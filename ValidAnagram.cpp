/*approach
  we simply check the count of chars in two strings and return whether they
  are equal are not*/
class Solution{
public:
    bool isAnagram(string s,string t){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        vector<int>ss(26),tt(26);
        for(int i=0;i<s.size();++i){
            ss[s[i]-'a']++;
            tt[t[i]-'a']++;
        }
        return ss == tt;
    }
};
