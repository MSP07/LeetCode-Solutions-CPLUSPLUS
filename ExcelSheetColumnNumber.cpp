/*approach
  this is reverse of number to title one 
  here A means 0 so iterating from start we simply
  multiply 26 and add the char val and return the int value*/
class Solution{
public:
    int titleToNumber(string columnTitle){
        int res = 0;
        for(char c:columnTitle){
            int val = c - 'A' + 1;
            res = res*26+val;
        }
        return res;
    }
};
