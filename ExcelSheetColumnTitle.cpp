/*approach
  simulation
  main challenge here is to convert string accordingly after number 25 since columnNumber is excel will 
  start from 0 we decrease 1 first and then we midulo the columnNumber add A to it and add it to string
  then reduce the columnNumber 26 times and repeat this process till we exhaust columnNumber and return 
  reversed version of string*/
class Solution{
public:
    string convertToTitle(int columnNumber){
        string ans = "";
        while(columnNumber>0){
            columnNumber--;
            ans += (char)(columnNumber%26+'A');
            columnNumber /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
