/*approach
  first we declare a string ans
  and we push the first char into it then we start iterating from index 1 till last
  anytime ans has chars and it is equal to s[i] then they are repeating and adjacent so we pop it
  else we add them to the string and finally return the string, this can also be done with stack
  repeating the same above process to save space and time we use string*/
class Solution{
public:
    string removeDuplicates(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        string ans = "";
        ans.push_back(s[0]);
        for(int i=1;i<s.size();++i){
            if(ans.size() && ans.back()==s[i]){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
