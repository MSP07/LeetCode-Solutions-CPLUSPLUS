/*approach
  stack,string
  to solve this optimally we use a string ans
  and iterate through the given string and if the char we r iterating
  is a digit and at the same time if the ans is not empty we pop the last
  char we appended we continue this to ensure we get only char as ans and
  finally return the ans string*/
class Solution {
private:
    bool isDigit(char c){
        return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'||c == '6'||c == '7'||c == '8'||c == '9';
    }
public:
    string clearDigits(string s) {
        string ans = "";
        for(char c:s){
            if(isDigit(c) && !ans.empty()){
                ans.pop_back();
                continue;
            }
            ans += c;
        }
        
        return ans;
    }
};
