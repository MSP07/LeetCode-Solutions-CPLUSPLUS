/*approach
  linear search
  we start from 1 all the way to n and whenever we
  come across a factor(n%i==0) we decrease the k and
  when k hits 0 we return that factor*/
class Solution{
public:
    int kthFactor(int n,int k){
        for(int i=1;i<=n;i++){
            if(n%i==0){
                k--;
                if(k==0)return i;
            }
        }
        return -1;
    }
};
