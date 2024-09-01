/*approach
  maths 
  if we write down the given queestion in terms of equation and try to find the answer then it will be
  n=a+(a+1)+(a+2)+⋯+(a+k−1) and our goal is to find a. Now given eq can be re-written to k * a + (1 + 2 + ... + (k - 1)) = k * a + (k * (k - 1)) / 2 = n.
  from this we get k * a = n - (k * (k - 1)) / 2. So a = n - (k * (k - 1)) / 2/k or (n - ((k * (k - 1)) / 2))/k. So k*(k-1)/2 should be less than n for
  whole a to be positive and if the (n-k*(k-1)/2) is divisible by k then we have a consecutive number for total sum so we increase ans and finally return it*/
class Solution{
public:
    int consecutiveNumbers(int n){
        int ans = 0;
        for(int k=1;k*(k-1)/2<n;++k){
            if((n-k*(k-1)/2)%k==0){
                ++ans;
            }
        }
        return ans;
    }
};
