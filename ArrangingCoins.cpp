/*approach
  binary search 
  we iterate binary search wise and find whether the sum of first mid numbers
  is equal to n if yes we return mid else we adjust and continue shrinking and searching*/
class Solution{
public:
    int arrangeCoins(int n){
        int left = 0, right = n;
        while(left<=right){
            long long mid = (left+right)/2;
            long long coins = (mid*(mid+1))/2;
            if(coins==n){
                return mid;
            }else if(coins < n){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }
};
