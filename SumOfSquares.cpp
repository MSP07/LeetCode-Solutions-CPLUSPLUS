/*approach
  two pointers one at start another at square root of given number
  if sum of squares of numbers at the two pointers equal the given sum
  we return true, if sum<c increase pointer at start else decrease pointer at square root
  after complete iteration no element found return false*/
class Solution{
public:
    int judgeSquareSum(int c){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        if(c==0)return true;
        long a = 0;
        long b = static_cast<long>(sqrt(c));
        while(a<=b){
            long long sum = a*a + b*b;
            if(sum==c)return true;
            else if(sum<c){
                ++a;
            }else{
                --b;
            }
        }
        return false;
    }
};
