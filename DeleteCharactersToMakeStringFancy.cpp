/*approach
  string, greedy
  we push the first 2 chars and check for prev and before prev chars 
  if they are not the same we add them to ans and return them*/
class Solution{
public:
    string makeFancyString(string s){
        string ans= "";
        for(char c:s){
            int n = ans.size();
            if(n<2 || !(ans[n-1]==c && ans[n-2]==c)){
                ans += c;
            }
        }
        return ans;
    }
};
