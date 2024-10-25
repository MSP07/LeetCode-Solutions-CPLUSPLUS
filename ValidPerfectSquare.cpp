/*approach
  binary search
  limits will be from 1 to num/2
  and we use binary search to search for square root if found return true else false*/
class Solution{
public:
    bool isPerfectSquare(int num){
        if(num==1)return true;
        int left = 1 ,right = num/2;
        while(left<=right){
            long long mid = left + (right-left)/2;
            if(mid*mid == num)return true;
            else if(mid*mid < num){
                left = mid + 1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};
