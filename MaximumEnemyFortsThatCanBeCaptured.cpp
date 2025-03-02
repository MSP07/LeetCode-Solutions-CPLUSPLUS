/*approach
  two pointers
  we simply check whether the fort is ours and calculate 
  the distance between them and forts that can be captured with prev
  and index i and return it*/
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int maxForts = 0;
        int prev = -1;
        for(int i=0;i<forts.size();i++){
            if(forts[i]==1 || forts[i]==-1){
                if(prev != -1 && forts[prev]!=forts[i]){
                    maxForts = max(maxForts,i-prev-1);
                }
                prev = i;
            }
        }
        return maxForts;
    }
};
