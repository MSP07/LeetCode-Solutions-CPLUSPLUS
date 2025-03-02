/*approach
  string, two pointers
  check every word for palindrome and return the first palindrome
  else finally return empty string*/
class Solution{
private:
    bool isPalindrome(string word){
        for(int i=0;i<word.size()/2;i++){
            if(word[i]!=word[word.size()-i-1])return false;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        // ios_base::sync_with_stdio(0);
        // cin.tie(0);
        for(string word:words){
            if(isPalindrome(word))return word;
        }
        return "";
    }
};
