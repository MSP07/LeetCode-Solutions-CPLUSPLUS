/*approach
  string, two pointers
  aim is to swap only letters so we keep two pointers
  one at start and another at end and if both are letters we swap and change pointers
  else we keep the pointer where the char is letter and change the other pointer accordingly
  and finally return the modified string*/
class Solution{
public:
    string reverseOnlyLetters(string s){
        int l = 0, r = s.size()-1;
        while(l<r){
            if(isalpha(s[l]) && isalpha(s[r])){
                swap(s[l],s[r]);
                l++;
                r--;
            }else if(isalpha(s[l])){
                r--;
            }else{
                l++;
            }
        }
        return s;
    }
};
