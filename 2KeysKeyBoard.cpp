/*approach
  we start with 0 steps and 2 factors as we copy 1 factor and we paste 1 factor
  if the given n can be achieved by the initialised factor then we simply increase
  steps by factors and reduce n by factors n /= factors if not then we increase the factors
  this goes on till n becomes less than 1 and we finally return the steps*/
class Solution{
public:
    int minSteps(int n){
        if(n==1)return 0;
        int steps = 0;
        int factors = 2;
        while(n>1){
            while(n%factors==0){
                steps += factors;
                n /= factors;
            }
            ++factors;
        }
        return steps;
    }
};
