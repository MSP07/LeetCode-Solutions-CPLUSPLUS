/*approach
  stack,string approach
  we just compare top element with the curr and if both form the sequence we are checking
  we pop them else we push the char and finally return the stack/string size*/
class Solution{
public:
    int minLength(string s){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(s.size()==1)return 1;
        string ans = "";
        for(char c:s){
            if(!ans.empty() && c == 'B' && ans.back() == 'A'){
                ans.pop_back();
            }else if(!ans.empty() && c == 'D' && ans.back() == 'C'){
                ans.pop_back();
            }else{
                ans.push_back(c);
            }
        }
        return ans.size();
    }
};
