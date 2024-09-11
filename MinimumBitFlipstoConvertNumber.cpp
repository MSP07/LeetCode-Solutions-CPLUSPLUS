/*approach
  we start by performing xor between the given two numbers which gives us a result
  that has no of distinct ones now we calculate that distinct ones has those are the ones
  that needs to be flipped and return them*/
class Solution{
public:
    int minBitFlips(int start,int end){
        int xorRes = start^end;
        int count = 0;
        while(xorRes){
            count += xorRes & 1;
            xorRes >>= 1;
        }
        return count;
    }
};
