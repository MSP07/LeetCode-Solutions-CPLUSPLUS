/*approach
  prefixSum
  instead of calculating all possible sequence we simply count the ones
  that are valid, we do this by summing up the num while we iterate and 
  keep track of max and min ones and after the iteration defining the boundaries
  right and left and finally return right-left+1 if the val is positive else 0*/
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long maxi = 0, mini = 0, sum = 0;
        for(int d:differences){
            sum += d;
            maxi = max(maxi,sum);
            mini = min(mini,sum);
        }
        long right = upper - maxi, left = lower - mini;
        return max(0L,right-left+1);
    }
};
