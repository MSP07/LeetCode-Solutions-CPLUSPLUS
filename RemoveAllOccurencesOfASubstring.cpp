/*approach
  string
  while we find the substring in the main string
  we keep on removing and finally return the modified string*/
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.size()>0 && s.find(part)<s.size()){
            s.erase(s.find(part),part.size());
        }
        return s;
    }
};
