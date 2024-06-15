/*approach
  we keep minop as k initially 
  and keep track of white count till k in nums
  we update minop and iterate from k to end
  if we find white color we increase the count but if there is a white in prev (i-k) then that should be recolored so we decrease the whitecolor
  and each time we update minop and finally after the loop we return ir*/
class Solution{
public:
    int minimumRecolors(string blocks,int k){
        int whiteCount = 0;
        int minOps = k;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W')whiteCount++;
        }
        minOps = min(minOps,whiteCount);
        for(int i=k;i<blocks.size();i++){
            if(blocks[i]=='W')whiteCount++;
            if(blocks[i-k]=='W')whiteCount--;
            minOps = min(minOps,whiteCount);
        }
        return minOps;
    }
};
