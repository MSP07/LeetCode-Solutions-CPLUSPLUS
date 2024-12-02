/*approach
  string, two pointers
  we start with ind = 1 as answer is 1 based indexing and we add the chars
  while iterating and if the substr of the ans string is same as searchWord then
  we return the ind else we incr ind and change word to empty string if not c == ' '
  we just add the char c to word and if nothing is found we finally return -1*/
class Solution{
public:
    int isPrefixOfWord(string sentence,string searchWord){
        int ind=1;
        string word = "";
        for(char c:sentence+" "){
            if(c==' '){
                if(word.size()>=searchWord.size() && word.substr(0,searchWord.size())==searchWord)return ind;
                ind++;
                word = "";
            }else{
                word += c;
            }
        }
        return -1;
    }
};
