/*approach
  KMP algorithm
  we first combine two strings the last part will be the given string and the first part will be the 
  reverse of the given string and from there we calculate the longest palindrome prefix that can make it 
  a palindrome then to identify the shortest we choose a len that will be stored in last of lps array
  we remove that from org string and return that substr from reversed string and return it*/
class Solution{
public:
    string shortestPalindrome(string s){
        string reverse_s = s;
        reverse(reverse_s.begin(),reverse_s.end());
        string combined = s + '#' + reverse_s;
        vector<int>lps(combined.size(),0);
        for(int i=1;i<combined.size();++i){
            int len = lps[i-1];
            while(len>0 && combined[i] != combined[len]){
                len = lps[len-1];
            }
            if(combined[i] == combined[len]){
                len++;
            }
            lps[i] = len;
        }
        int to_add_len = s.size() - lps.back();
        string to_add = reverse_s.substr(0,to_add_len);
        return to_add + s;
    }
};

const auto init = [](){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
