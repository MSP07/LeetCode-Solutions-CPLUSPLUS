/*approach
  similar to fibonacci except the base case where n=0 and n=1 gets 1 way to be climbed
  then we keep two var curr and prev where we store curr temporarily change curr to curr+prev and update prev to temp(prev pos of curr)*/
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1)return 1;
        int curr = 1, prev=1;
        for(int i=2;i<=n;i++){
            int temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};
