/*approach
  string, simulation
  we just follow the conditions given and change the
  bool flag accordingly whether the given number is a 
  valid digit or not and finally return the bool value*/
class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        bool hasDigit = false; 
        bool hasDot = false;   
        bool hasExponent = false; 
        bool hasSign = false;  
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(isdigit(ch)) {
                hasDigit = true; 
            }else if(ch == '+' || ch == '-'){
                if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')){
                    return false;
                }
                hasSign = true;
            }else if(ch == '.'){
                if(hasDot || hasExponent){
                    return false;
                }
                hasDot = true;
            }else if(ch == 'e' || ch == 'E'){
                if(hasExponent || !hasDigit){
                    return false;
                }
                hasExponent = true;
                hasDigit = false; 
            }else{
                return false;
            }
        }
        return hasDigit;
    }
};
