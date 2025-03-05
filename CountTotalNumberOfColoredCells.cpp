/*approach
  linear traversal, math
  the sequence starts from 1 and the pattern is for each extra n
  or each n+1 4 cells are colored so we start from 1 and from 1 to n-1
  we multiply that many cells and add them to ans else we can simply use the 
  math formula for first n multiple of 4 sum*/
class Solution{
public: 
    long long coloredCells(int n){
        //iterative approach
        long long ans = 1;
        for(int i=1;i<n;i++){
            ans += (4*i);
        }
        return ans;
        //formula answer
        return 1 + (long long)2*n*(n-1);
    }
};
