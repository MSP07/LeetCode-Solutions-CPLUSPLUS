/*approach
  two pointer
  one pointer at 0 and another we will place it when we find
  ch in word and we reverse that part alone and return the string*/
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0,j=0;
        for(int k=0;k<word.size();k++){
            if(word[k]==ch){
                j = k;
                break;
            }
        }
        while(i<j){
            swap(word[i],word[j]);
            i++;j--;
        }
        return word;
    }
};
