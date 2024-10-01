/*approach
  either 1 or 0 is possible when modulo is done by 2
  if there is a 1 bit then we add that to ans else we will add 0 to ans
  so ans += (n%2) and n will be reduced 2 times n /= 2 to move leftwards
  and find the remaining 1 bits in the number and finally ans is returned*/
class Solution{
public:
    int hammingWeight(int n){
        int ans = 0;
        while(n>0){
            ans += (n%2);
            n /= 2;
        }
        return ans;
    }
};
