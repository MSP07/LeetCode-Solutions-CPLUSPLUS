/*approach
  dp
  we start of with intially 1
  and we intialise 3 multiples 2,3 and 5
  whichever is min of that will be out next element
  now whichever of them is min we update that pointer to +1 and update that
  element to prev number*that number's pointer. finally we return the last element*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>uglyNumber(n,0);
        uglyNumber[0]=1;
        int i2 = 0, i3 = 0, i5 = 0;
        int nextMultipleOf2 = 2;
        int nextMultipleOf3 = 3;
        int nextMultipleOf5 = 5;
        for(int i=1;i<n;++i){
            int nextUglyNumber = min(nextMultipleOf2,min(nextMultipleOf3,nextMultipleOf5));
            uglyNumber[i] = nextUglyNumber;
            if(nextUglyNumber == nextMultipleOf2){
                ++i2;
                nextMultipleOf2 = uglyNumber[i2]*2;
            }
            if(nextUglyNumber == nextMultipleOf3){
                ++i3;
                nextMultipleOf3 = uglyNumber[i3]*3;
            }
            if(nextUglyNumber == nextMultipleOf5){
                ++i5;
                nextMultipleOf5 = uglyNumber[i5]*5;
            }
        }
        return uglyNumber[n-1];
    }
};
