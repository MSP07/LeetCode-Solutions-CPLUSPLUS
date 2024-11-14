/*approach
  binary search
  similar to koko eating bananas problem we need to find the ceil of every mid
  if the ceil is higher than n then allocation is possible for the minimized max one
  and still allocation can be possible so shrink to window to mid+1,right else
  shrink the window to left,mid and due to opp polarity we return the left as answer.
  Here we take left,right to be not indices but vals from 1,100000*/
class Solution{
private:
    bool isPossible(int x,vector<int>& quantities,int n){
        int sum = 0;
        for(int quantity:quantities){
            sum += (quantity+x-1)/x;
        }
        return sum>n;
    }
public:
    int minimizedMaximum(int n,vector<int>& quantities){
        int left=1,right=100000;
        while(left<right){
            int mid = left+(right-left)/2;
            if(isPossible(mid,quantities,n))left=mid+1;
            else right = mid;
        }
        return left;
    }
};
