/*approach
  two pointers, greedy
  interate from both ends if both chars are same shrink the window
  else we check for palindrome in either left+1 to right substring or left,right-1 substring
  if either returns true then it is possible to make this string palindorme after one deletion
  else not*/
class Solution{
private:
    bool isPalindrome(string s,int l,int h){
        while(l<=h){
            if(s[l]!=s[h])return false;
            l++;
            h--;
        }
        return true;
    }
public:
    bool validPalindrome(string s){
        int l = 0, h = s.size()-1;
        while(l<=h){
            if(s[l]==s[h]){
                l++;
                h--;
            }else{
                return isPalindrome(s,l+1,h) || isPalindrome(s,l,h-1);
            }
        }
        return true;
    }
};
