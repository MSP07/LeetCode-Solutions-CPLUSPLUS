/*approach
  two pointers, greedy, string, simulation
  we start of by iterating from start and from end 
  if both are equal we keep on iterating else we check which one is lexicographically smallest
  and we change the other one to that small one and finally return the string*/
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                if(s[i]<s[j]){
                    s[j] = s[i];
                }else{
                    s[i] = s[j];
                }
            }
            i++;
            j--;
        }
        return s;
    }
};
