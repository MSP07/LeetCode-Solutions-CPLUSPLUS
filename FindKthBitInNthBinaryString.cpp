/*approach
  recursion 
  base case is 1 we return '0' and by default every middle bbit will be '1'
  so if the mid we calculate by calculating lenght that will 2 power n - 1
  is equal to k we return 1 else if its less we return n-1,k and if its greater
  then that is the mirror valas per question so we calculate the mirror index by
  len-k+1 and we change the char of that bit in other words we inverse that and return it*/
class Solution{
private:
    char helper(int n,int k){
        if(n==1)return '0';
        int len = (1<<n)-1;
        int mid = len/2 + 1;
        if(mid==k)return '1';
        else if(mid<k)return helper(n-1,k);
        else{
            int mirror = len-k+1;
            return helper(n-1,mirror) == '0' ? '1' : '0';
        }
    }
public:
    char findKthBit(int n,int k){
        return helper(n,k);
    }
};
