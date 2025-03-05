/*approach
  math
  first we find the upper limit of given number
  till how much power of 3 does this number extend and then 
  till there is n we try to subtract the highest power we found from n
  and reduce that power and again reduce that from num at any point if n is 
  not reachable(more than) the 3 power of num then we return false else after full iteration  
  we return true*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int power = 0;
        while(pow(3,power)<=n){
            power++;
        }
        while(n>0){
            if(n>=pow(3,power)) n -= pow(3,power);
            if(n>=pow(3,power))return false;
            power--;
        }
        return true;
    }
};
