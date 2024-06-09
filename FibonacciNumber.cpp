/*approach
  we use two pointers or var that keep track of prev element and element before that
  and we update them as we iterate through till the given number*/
class Solution{
public:
    int fib(int n){
        if(n<=1)return n;
        int prev2 = 0, prev = 1;
        for(int i=2;i<=n;i++){
            int curri = prev+prev2;
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
};
