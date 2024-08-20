/*approach
  we start with result as 0 and we progressively increase result with 1
  till n is exhausted and we subtract that result from n and finally return the
  result. This works because we progressively add upto 1+2+3+...upto m and so the floors
  are exhausted and we get the desired floor when we exhaust the n*/
class Solution{
public:
    int twoEggDrop(int n){
        int result = 0;
        while(n>0){
            ++result;
            n -= result;
        }
        return result;
    }
};
