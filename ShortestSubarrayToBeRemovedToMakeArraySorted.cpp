/*approach
  two pointers, prefix
  first we find the points where the sorting ends both from first and 
  from last then we first calculate whether the array is already sorted
  if so then the sorting end from end will go all the way to array's end
  after finding sorting end from last also we calculate the length of subarray first
  then from left till end we calculate the min subarray that can be removed and finally
  return its lenght*/
class Solution{
public:
    int findLengthOfShortestSubarray(vector<int>& arr){
        int n = arr.size();
        int left = 0;
        while(left+1<n && arr[left]<=arr[left+1]){
            left++;
        }
        if(left==n-1)return 0;
        int right = n-1;
        while(right>0 && arr[right-1]<=arr[right]){
            right--;
        }
        int res = min(n-left-1,right);
        int i=0,j=right;
        while(i<=left && j<n){
            if(arr[i]<=arr[j]){
                res = min(res,j-i-1);
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
};
