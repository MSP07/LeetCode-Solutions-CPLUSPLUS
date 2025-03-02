/*approach
  string, simulation
  we keep a temp string start concenating strings in the words
  and when our temp has same size as s we return whether they are same or not
  if none of the concatination gives length same as s then we return false finally 
  this works because the given string s must form right from start of words and not from anywhere middle*/
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp = "";
        for(string word:words){
            temp += word;
            if(temp.size()==s.size()){
                return temp == s;
            }
        }
        return false;
    }
};
