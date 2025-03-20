/*approach
  bit manipulation, maths
  we use the mathematical formula to find ith bit in gray code
  sequence g(i) = (i^(i>>1)), append it to array and return the res*/
class Solution{
public:
    vector<int> grayCode(int n){
        vector<int>res;
        int numElements = 1 << n;
        for(int i=0;i<numElements;i++){
            res.push_back(i^(i>>1));
        }
        return res;
    }
};
