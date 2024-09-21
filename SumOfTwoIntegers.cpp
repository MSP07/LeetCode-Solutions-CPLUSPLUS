/*approach
  bit manipulation
  we take sum with carry
  for sum we take XOR which gives 0^1 = 1 and 1^0 = 1 whereas 0 for remaining so this will satisfy sum without carry
  for carry we take AND it gices 1&1 = 1 so we first calc carry and store the sum without carry then carry is set to a bit left
  and when no more carry is left we return the overall sum stored in a*/
class Solution{
public:
    int getSum(int a,int b){
        while(b != 0){
            int carry = (a&b);
            a = a^b;
            b = carry<<1;
        }
        return a;
    }
};
