/*approach
  string
  to be circular first and last char should be equal and if we see a space then prev and next char
  must be equal to if any of these condition fail we return false*/
class Solution{
public:
    bool isCircularSentence(string sentence){
        int n = sentence.size();
        if(sentence[0]!=sentence[n-1])return false;
        for(int i=0;i<n-1;++i){
            if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1])return false;
        }
        return true;
    }
};
