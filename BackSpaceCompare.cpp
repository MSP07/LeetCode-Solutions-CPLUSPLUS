/*approach
  two pointers, simulation  
  we iterate add the string and if we come across '#' we erase the prev one
  and do the same for string t also and finally return whether both the resultant 
  strings are equal or not*/
class Solution {
private:
    string process(string str) {
        string result;
        for(char c : str){
            if(c == '#'){
                if(!result.empty()){
                    result.pop_back();
                }
            }else{
                result.push_back(c);
            }
        }
        return result;
    }
public:
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};
