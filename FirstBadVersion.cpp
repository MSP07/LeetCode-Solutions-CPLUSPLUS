/*approach
  binary search
  we use binary search to find the first bad version 
  the first version is responisble for contaminating the succesing versions too
  so to save time we use binary search rather than a normal traversal*/
class Solution{
public:
    int firstBadVersion(int n){
        int left = 1, right = n;
        while(left<right){
            int mid = left + (right-left)/2;
            if(isBadVersion(mid)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};
