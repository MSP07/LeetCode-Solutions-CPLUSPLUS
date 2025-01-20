/*approach
  bit manipulation
  XOR btn numbers provide 1 for diff bits and 0 for same bits
  to minimize the ans we must align num1's bits as closely as possible
  if num1 as less bits then additional bits are added from LSB to ensure 
  and as same no of bits as num2*/
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsNum2 = __builtin_popcount(num2); 
        int x = 0;
        for (int i=31;i>=0&&setBitsNum2>0;i--){
            if (num1 & (1<<i)){ 
                x |= (1 << i);    
                setBitsNum2--;   
            }
        }
        for (int i=0;i<32&&setBitsNum2>0;i++){
            if (!(x & (1<<i))){ 
                x |= (1<<i);   
                setBitsNum2--;    
            }
        }
        return x;
    }
};
