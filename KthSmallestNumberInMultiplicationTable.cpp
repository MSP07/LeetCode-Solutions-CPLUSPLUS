/*approach
  binary search
  we keep left and right at 1 and m*n respectively
  we calculate mid and take count  while running loop from 1 to m, how many elements in that row
  are less than or equal to mid. The number of such elements in the i-th row is min(mid / i, n).if the count is 
  less than k we move left forward else we bring right to mid and at last we return left*/
  
class Solution{
public:
    int findkthNumber(int m,int n,int k){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int left = 1, right = m*n;
        while(left < right){
            int mid = left + (right - left) / 2;
            int count = 0;
            for(int i=1;i<=m;++i){
                count += min(mid/i,n);
            }
            if(count < k){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
