/*approach
  if even no of times they r in front else in reverse
  we make use of the above statement*/
class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int rounds = k/n, rem = k%n;
        if(rounds%2==0) return rem;
        else return (n-rem);
    }
};
