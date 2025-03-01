/*approach
  string
  we simply keep track of the count of same chars 0's or 1's
  when the streak breaks when s[i-1] != s[i] then we add the min of
  1's count and 0's count to the ans and keep the streak curr as 1 again
  else we incr the curr and finally return the ans with min of prev,curr*/
class Solution{
public:
    int countBinarySubstrings(string s){
        int ans = 0, prev = 0, curr = 1;
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]){
                ans += min(prev,curr);
                prev = curr;
                curr = 1;
            }else{
                curr++;
            }
        }
        return ans + min(prev,curr);
    }
};
