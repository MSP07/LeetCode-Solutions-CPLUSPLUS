/*approach
  string
  given every even substring should have same no of 0's and 1's 
  if we break down and reach the base even substring it will be of length 2 so instead of checking for all even substrings
  we can check for substring of 2 nothing but adjacent elements and move pointer by 2 if they are same then no change is needed
  whereas if they are diff then change needs to be done and we incr the change and finally after complete traversal we return the changes*/
class Solution{
public:
    int minChanges(string s){
        int n = s.size();
        int changes = 0;
        for(int i=0;i<n-1;i+=2){
            if(s[i]!=s[i+1]){
                ++changes;
            }
        }
        return changes;
    }
};
