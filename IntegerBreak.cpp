/*approach
  we use basic maths simulation and derive to a recursive pattern and find the ans*/
class Solution{
public:
    int integerBreak(int n){
        if(n==2)return 1;
        if(n==3)return 2;
        int ans = 1;
        while(n>4){
            ans *= 3;
            n -= 3;
        }
        return ans*n;
    }
};
