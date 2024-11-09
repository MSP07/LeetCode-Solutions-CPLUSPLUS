/*approach
  bit manipulation
  till we have n-1 places we need to check for answer
  we make the result accoringly such that result and prev element
  will give x then change the remaining, poistion parameters accordingly
  and finally return the result*/
class Solution{
public:
    long long minEnd(int n,int x){
        long result = x, remaining = n-1, position = 1;
        while(remaining){
            if(!(x&position)){
                result |= (remaining&1)*position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        return result;
    }
};
