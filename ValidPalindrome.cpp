/*approach
  two pointers approach
  brute force will be to add all char into a string both from start to end and end to start
  then return whether both are equal
  optimal soln will be to have a pointer on start and end and skip chars that are not alphabetic
  compare both the chars in lower case and return false at any point if they are not equal and return
  true if the process is complete and no objection is found*/
class Solution{
public:
    bool isPalindrome(string s){
        if(s.size()==1)return true;
        int left = 0, right = s.size()-1;
        while(left<right){
            while(left<right && !isalnum(s[left])){
                left++;
            }
            while(left<right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
