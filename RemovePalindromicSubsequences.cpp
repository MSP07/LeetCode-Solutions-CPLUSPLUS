/*approach
  two pointers
  if the string is palindrome then 1 else there is always a 
  a way to represent the given string as a palindorme + normal stirng
  so its either 1 is given string is palindrome else 2*/
class Solution {
private:
    bool ispalindrome(string s){
        int left = 0;
        int right = s.length()-1;
        while(left < right){
            if(s[left] != s[right]) return false;
            else{
                left++;
                right--;
            }
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if(ispalindrome(s)) return 1;
        else return 2;
    }
};
